# Copyright (c) 2017, Apple Inc. All rights reserved.
#
# Use of this source code is governed by a BSD-3-clause license that can be
# found in the LICENSE.txt file or at https://opensource.org/licenses/BSD-3-Clause

import json
import tempfile
import unittest

from ..utils import load_boston
from coremltools._deps import _HAS_SKLEARN, _HAS_XGBOOST
from coremltools.models.utils import _macos_version

if _HAS_XGBOOST:
    import xgboost

    from coremltools.converters import xgboost as xgb_converter

if _HAS_SKLEARN:
    from sklearn.ensemble import GradientBoostingRegressor
    from sklearn.preprocessing import OneHotEncoder

    from coremltools.converters import sklearn as skl_converter


@unittest.skipIf(not _HAS_SKLEARN, "Missing scikit-learn. Skipping tests.")
class GradientBoostingRegressorScikitTest(unittest.TestCase):
    """
    Unit test class for testing scikit-learn converter.
    """

    @classmethod
    def setUpClass(cls):
        """
        Set up the unit test by loading the dataset and training a model.
        """
        scikit_data = load_boston()
        scikit_model = GradientBoostingRegressor(random_state=1)
        scikit_model.fit(scikit_data["data"], scikit_data["target"])

        s = 0
        for est in scikit_model.estimators_:
            for e in est:
                s = s + e.tree_.node_count
        cls.scikit_model_node_count = s

        # Save the data and the model
        cls.scikit_data = scikit_data
        cls.scikit_model = scikit_model

    def test_conversion(self):
        input_names = self.scikit_data["feature_names"]
        output_name = "target"
        spec = skl_converter.convert(
            self.scikit_model, input_names, "target"
        ).get_spec()
        self.assertIsNotNone(spec)

        # Test the model class
        self.assertIsNotNone(spec.description)

        # Test the interface class
        self.assertEqual(spec.description.predictedFeatureName, "target")

        # Test the inputs and outputs
        self.assertEqual(len(spec.description.output), 1)
        self.assertEqual(spec.description.output[0].name, "target")
        self.assertEqual(
            spec.description.output[0].type.WhichOneof("Type"), "doubleType"
        )
        for input_type in spec.description.input:
            self.assertEqual(input_type.type.WhichOneof("Type"), "doubleType")
        self.assertEqual(
            sorted(input_names), sorted(map(lambda x: x.name, spec.description.input))
        )

        tr = spec.pipelineRegressor.pipeline.models[
            -1
        ].treeEnsembleRegressor.treeEnsemble
        self.assertIsNotNone(tr)
        self.assertEqual(len(tr.nodes), self.scikit_model_node_count)

    def test_conversion_bad_inputs(self):

        # Error on converting an untrained model
        with self.assertRaises(Exception):
            model = GradientBoostingRegressor()
            spec = skl_converter.convert(model, "data", "out")

        # Check the expected class during conversion.
        with self.assertRaises(Exception):
            model = OneHotEncoder()
            spec = skl_converter.convert(model, "data", "out")


@unittest.skipIf(_macos_version() >= (10, 16), "rdar://problem/84898245")
@unittest.skipIf(not _HAS_SKLEARN, "Missing scikit-learn. Skipping tests.")
@unittest.skipIf(not _HAS_XGBOOST, "Skipping, no xgboost")
class BoostedTreeRegressorXGboostTest(unittest.TestCase):
    @classmethod
    def setUpClass(self):
        """
        Set up the unit test by loading the dataset and training a model.
        """
        if not _HAS_XGBOOST:
            return
        if not _HAS_SKLEARN:
            return

        scikit_data = load_boston()
        dtrain = xgboost.DMatrix(
            scikit_data["data"],
            label=scikit_data["target"],
            feature_names=scikit_data["feature_names"],
        )
        xgb_model = xgboost.train({}, dtrain, 1)

        # Save the data and the model
        self.scikit_data = scikit_data
        self.xgb_model = xgb_model
        self.feature_names = self.scikit_data["feature_names"]

        # train a booster with special characters in feature names
        x = scikit_data['data']
        # prepare feature names with special chars
        self.feature_names_special_chars = [f'\t"{i}"\n' for i in range(x.shape[1])]
        # create training dmatrix
        dm = xgboost.DMatrix(x, label=scikit_data["target"], feature_names=self.feature_names_special_chars)
        # train booster
        self.xgb_model_special_chars = xgboost.train({}, dm, 1)
        # create XGBClassifier from a copy of trainer booster
        self.xgb_regressor_special_chars = xgboost.XGBRegressor(xgb_model=self.xgb_model_special_chars.copy(), n_estimators=1)
        self.xgb_regressor_special_chars.fit(x, scikit_data["target"])

    def test_conversion(self):

        feature_names = self.scikit_data["feature_names"]
        output_name = "target"
        spec = xgb_converter.convert(self.xgb_model, feature_names, "target").get_spec()
        self.assertIsNotNone(spec)

        # Test the model class
        self.assertIsNotNone(spec.description)
        self.assertIsNotNone(spec.treeEnsembleRegressor)

        # Test the interface class
        self.assertEqual(spec.description.predictedFeatureName, "target")

        # Test the inputs and outputs
        self.assertEqual(len(spec.description.output), 1)
        self.assertEqual(spec.description.output[0].name, "target")
        self.assertEqual(
            spec.description.output[0].type.WhichOneof("Type"), "doubleType"
        )
        for input_type in spec.description.input:
            self.assertEqual(input_type.type.WhichOneof("Type"), "doubleType")
        self.assertEqual(
            sorted(self.feature_names),
            sorted(map(lambda x: x.name, spec.description.input)),
        )

        # Test the linear regression parameters.
        tr = spec.treeEnsembleRegressor.treeEnsemble
        self.assertIsNotNone(tr)
        self.assertEqual(len(tr.nodes), 23)

    def test_conversion_from_file(self):

        output_name = "target"
        feature_names = self.feature_names

        xgb_model_json = tempfile.NamedTemporaryFile("tree_model.json").name
        xgb_json_out = self.xgb_model.get_dump(dump_format="json")
        with open(xgb_model_json, "w") as f:
            json.dump(xgb_json_out, f)
        spec = xgb_converter.convert(xgb_model_json, feature_names, "target").get_spec()
        self.assertIsNotNone(spec)

        # Test the model class
        self.assertIsNotNone(spec.description)
        self.assertIsNotNone(spec.treeEnsembleRegressor)

        # Test the interface class
        self.assertEqual(spec.description.predictedFeatureName, "target")

        # Test the inputs and outputs
        self.assertEqual(len(spec.description.output), 1)
        self.assertEqual(spec.description.output[0].name, "target")
        self.assertEqual(
            spec.description.output[0].type.WhichOneof("Type"), "doubleType"
        )
        for input_type in spec.description.input:
            self.assertEqual(input_type.type.WhichOneof("Type"), "doubleType")
        self.assertEqual(
            sorted(self.feature_names),
            sorted(map(lambda x: x.name, spec.description.input)),
        )

        # Test the linear regression parameters.
        tr = spec.treeEnsembleRegressor.treeEnsemble
        self.assertIsNotNone(tr)
        self.assertEqual(len(tr.nodes), 23)

    def test_unsupported_conversion(self):

        feature_names = self.scikit_data["feature_names"]
        output_name = "target"
        xgb_model = xgboost.XGBRegressor(objective="reg:gamma")
        xgb_model.fit(self.scikit_data["data"], self.scikit_data["target"])
        with self.assertRaises(ValueError):
            spec = xgb_converter.convert(xgb_model, feature_names, "target")

        xgb_model = xgboost.XGBRegressor(objective="reg:tweedie")
        xgb_model.fit(self.scikit_data["data"], self.scikit_data["target"])
        with self.assertRaises(ValueError):
            spec = xgb_converter.convert(xgb_model, feature_names, "target")

    def test_conversion_bad_inputs(self):

        # Error on converting an untrained model
        with self.assertRaises(TypeError):
            model = GradientBoostingRegressor()
            spec = xgb_converter.convert(model, "data", "out")

        # Check the expected class during conversion
        with self.assertRaises(TypeError):
            model = OneHotEncoder()
            spec = xgb_converter.convert(model, "data", "out")

    def test_conversion_special_characters_in_feature_names(self):
        # this test should fail if conversion function does not implement the
        # special characters in feature names fix

        # test both sklearn wrapper and raw booster
        for model in [self.xgb_model_special_chars, self.xgb_regressor_special_chars]:

            # process as usual
            output_name = "target"
            spec = xgb_converter.convert(
                model, self.feature_names_special_chars, "target")\
                .get_spec()

            self.assertIsNotNone(spec)

            # Test the model class
            self.assertIsNotNone(spec.description)
            self.assertIsNotNone(spec.treeEnsembleRegressor)

            # Test the interface class
            self.assertEqual(spec.description.predictedFeatureName, "target")

            # Test the inputs and outputs
            self.assertEqual(len(spec.description.output), 1)
            self.assertEqual(spec.description.output[0].name, "target")
            self.assertEqual(
                spec.description.output[0].type.WhichOneof("Type"), "doubleType"
            )
            for input_type in spec.description.input:
                self.assertEqual(input_type.type.WhichOneof("Type"),
                                 "doubleType")
            self.assertEqual(
                sorted(self.feature_names_special_chars),
                sorted(map(lambda x: x.name, spec.description.input)),
            )

            # Test the linear regression parameters.
            tr = spec.treeEnsembleRegressor.treeEnsemble
            self.assertIsNotNone(tr)
            self.assertEqual(len(tr.nodes), 23)
