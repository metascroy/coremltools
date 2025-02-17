// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DictVectorizer.proto

#include "DictVectorizer.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace CoreML {
namespace Specification {
constexpr DictVectorizer::DictVectorizer(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : _oneof_case_{}{}
struct DictVectorizerDefaultTypeInternal {
  constexpr DictVectorizerDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~DictVectorizerDefaultTypeInternal() {}
  union {
    DictVectorizer _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT DictVectorizerDefaultTypeInternal _DictVectorizer_default_instance_;
}  // namespace Specification
}  // namespace CoreML
namespace CoreML {
namespace Specification {

// ===================================================================

class DictVectorizer::_Internal {
 public:
  static const ::CoreML::Specification::StringVector& stringtoindex(const DictVectorizer* msg);
  static const ::CoreML::Specification::Int64Vector& int64toindex(const DictVectorizer* msg);
};

const ::CoreML::Specification::StringVector&
DictVectorizer::_Internal::stringtoindex(const DictVectorizer* msg) {
  return *msg->Map_.stringtoindex_;
}
const ::CoreML::Specification::Int64Vector&
DictVectorizer::_Internal::int64toindex(const DictVectorizer* msg) {
  return *msg->Map_.int64toindex_;
}
void DictVectorizer::set_allocated_stringtoindex(::CoreML::Specification::StringVector* stringtoindex) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  clear_Map();
  if (stringtoindex) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<
            ::PROTOBUF_NAMESPACE_ID::MessageLite>::GetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(stringtoindex));
    if (message_arena != submessage_arena) {
      stringtoindex = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, stringtoindex, submessage_arena);
    }
    set_has_stringtoindex();
    Map_.stringtoindex_ = stringtoindex;
  }
  // @@protoc_insertion_point(field_set_allocated:CoreML.Specification.DictVectorizer.stringToIndex)
}
void DictVectorizer::clear_stringtoindex() {
  if (_internal_has_stringtoindex()) {
    if (GetArenaForAllocation() == nullptr) {
      delete Map_.stringtoindex_;
    }
    clear_has_Map();
  }
}
void DictVectorizer::set_allocated_int64toindex(::CoreML::Specification::Int64Vector* int64toindex) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  clear_Map();
  if (int64toindex) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<
            ::PROTOBUF_NAMESPACE_ID::MessageLite>::GetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(int64toindex));
    if (message_arena != submessage_arena) {
      int64toindex = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, int64toindex, submessage_arena);
    }
    set_has_int64toindex();
    Map_.int64toindex_ = int64toindex;
  }
  // @@protoc_insertion_point(field_set_allocated:CoreML.Specification.DictVectorizer.int64ToIndex)
}
void DictVectorizer::clear_int64toindex() {
  if (_internal_has_int64toindex()) {
    if (GetArenaForAllocation() == nullptr) {
      delete Map_.int64toindex_;
    }
    clear_has_Map();
  }
}
DictVectorizer::DictVectorizer(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:CoreML.Specification.DictVectorizer)
}
DictVectorizer::DictVectorizer(const DictVectorizer& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite() {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  clear_has_Map();
  switch (from.Map_case()) {
    case kStringToIndex: {
      _internal_mutable_stringtoindex()->::CoreML::Specification::StringVector::MergeFrom(from._internal_stringtoindex());
      break;
    }
    case kInt64ToIndex: {
      _internal_mutable_int64toindex()->::CoreML::Specification::Int64Vector::MergeFrom(from._internal_int64toindex());
      break;
    }
    case MAP_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:CoreML.Specification.DictVectorizer)
}

inline void DictVectorizer::SharedCtor() {
clear_has_Map();
}

DictVectorizer::~DictVectorizer() {
  // @@protoc_insertion_point(destructor:CoreML.Specification.DictVectorizer)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

inline void DictVectorizer::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (has_Map()) {
    clear_Map();
  }
}

void DictVectorizer::ArenaDtor(void* object) {
  DictVectorizer* _this = reinterpret_cast< DictVectorizer* >(object);
  (void)_this;
}
void DictVectorizer::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void DictVectorizer::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void DictVectorizer::clear_Map() {
// @@protoc_insertion_point(one_of_clear_start:CoreML.Specification.DictVectorizer)
  switch (Map_case()) {
    case kStringToIndex: {
      if (GetArenaForAllocation() == nullptr) {
        delete Map_.stringtoindex_;
      }
      break;
    }
    case kInt64ToIndex: {
      if (GetArenaForAllocation() == nullptr) {
        delete Map_.int64toindex_;
      }
      break;
    }
    case MAP_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = MAP_NOT_SET;
}


void DictVectorizer::Clear() {
// @@protoc_insertion_point(message_clear_start:CoreML.Specification.DictVectorizer)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  clear_Map();
  _internal_metadata_.Clear<std::string>();
}

const char* DictVectorizer::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .CoreML.Specification.StringVector stringToIndex = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_stringtoindex(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .CoreML.Specification.Int64Vector int64ToIndex = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_int64toindex(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<std::string>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* DictVectorizer::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CoreML.Specification.DictVectorizer)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .CoreML.Specification.StringVector stringToIndex = 1;
  if (_internal_has_stringtoindex()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::stringtoindex(this), target, stream);
  }

  // .CoreML.Specification.Int64Vector int64ToIndex = 2;
  if (_internal_has_int64toindex()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::int64toindex(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CoreML.Specification.DictVectorizer)
  return target;
}

size_t DictVectorizer::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CoreML.Specification.DictVectorizer)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  switch (Map_case()) {
    // .CoreML.Specification.StringVector stringToIndex = 1;
    case kStringToIndex: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *Map_.stringtoindex_);
      break;
    }
    // .CoreML.Specification.Int64Vector int64ToIndex = 2;
    case kInt64ToIndex: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *Map_.int64toindex_);
      break;
    }
    case MAP_NOT_SET: {
      break;
    }
  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void DictVectorizer::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const DictVectorizer*>(
      &from));
}

void DictVectorizer::MergeFrom(const DictVectorizer& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CoreML.Specification.DictVectorizer)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  switch (from.Map_case()) {
    case kStringToIndex: {
      _internal_mutable_stringtoindex()->::CoreML::Specification::StringVector::MergeFrom(from._internal_stringtoindex());
      break;
    }
    case kInt64ToIndex: {
      _internal_mutable_int64toindex()->::CoreML::Specification::Int64Vector::MergeFrom(from._internal_int64toindex());
      break;
    }
    case MAP_NOT_SET: {
      break;
    }
  }
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
}

void DictVectorizer::CopyFrom(const DictVectorizer& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CoreML.Specification.DictVectorizer)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DictVectorizer::IsInitialized() const {
  return true;
}

void DictVectorizer::InternalSwap(DictVectorizer* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(Map_, other->Map_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
}

std::string DictVectorizer::GetTypeName() const {
  return "CoreML.Specification.DictVectorizer";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Specification
}  // namespace CoreML
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::CoreML::Specification::DictVectorizer* Arena::CreateMaybeMessage< ::CoreML::Specification::DictVectorizer >(Arena* arena) {
  return Arena::CreateMessageInternal< ::CoreML::Specification::DictVectorizer >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
