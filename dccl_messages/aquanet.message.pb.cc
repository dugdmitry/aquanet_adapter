// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: aquanet.message.proto

#include "aquanet.message.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

class AquanetMessageDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<AquanetMessage>
      _instance;
} _AquanetMessage_default_instance_;
namespace protobuf_aquanet_2emessage_2eproto {
static void InitDefaultsAquanetMessage() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_AquanetMessage_default_instance_;
    new (ptr) ::AquanetMessage();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::AquanetMessage::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_AquanetMessage =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsAquanetMessage}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_AquanetMessage.base);
}

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::AquanetMessage, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::AquanetMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::AquanetMessage, ros_msg_id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::AquanetMessage, x_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::AquanetMessage, y_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::AquanetMessage, z_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::AquanetMessage, body_message_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::AquanetMessage, veh_class_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::AquanetMessage, battery_ok_),
  4,
  1,
  2,
  3,
  0,
  6,
  5,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 12, sizeof(::AquanetMessage)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_AquanetMessage_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "aquanet.message.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\025aquanet.message.proto\032\034dccl/option_ext"
      "ensions.proto\"\304\002\n\016AquanetMessage\022+\n\nros_"
      "msg_id\030\001 \002(\rB\027\242\?\024 \001)\000\000\000\000\000\000\000\0001\000\000\000\000\000\000$@\022\"\n"
      "\001x\030\002 \001(\001B\027\242\?\024 \001)\000\000\000\000\000\000$\3001\000\000\000\000\000\000$@\022\"\n\001y\030\003"
      " \001(\001B\027\242\?\024 \001)\000\000\000\000\000\000$\3001\000\000\000\000\000\000$@\022\"\n\001z\030\004 \001(\001"
      "B\027\242\?\024 \001)\000\000\000\000\000\000$\3001\000\000\000\000\000\000$@\022\034\n\014body_messag"
      "e\030\005 \001(\tB\006\242\?\003H\310\001\022/\n\tveh_class\030\006 \001(\0162\034.Aqu"
      "anetMessage.VehicleClass\022\022\n\nbattery_ok\030\007"
      " \001(\010\"*\n\014VehicleClass\022\007\n\003AUV\020\001\022\007\n\003USV\020\002\022\010"
      "\n\004SHIP\020\003:\n\242\?\007\010\001\020\200\002(\003"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 380);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "aquanet.message.proto", &protobuf_RegisterTypes);
  ::protobuf_dccl_2foption_5fextensions_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_aquanet_2emessage_2eproto
const ::google::protobuf::EnumDescriptor* AquanetMessage_VehicleClass_descriptor() {
  protobuf_aquanet_2emessage_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_aquanet_2emessage_2eproto::file_level_enum_descriptors[0];
}
bool AquanetMessage_VehicleClass_IsValid(int value) {
  switch (value) {
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const AquanetMessage_VehicleClass AquanetMessage::AUV;
const AquanetMessage_VehicleClass AquanetMessage::USV;
const AquanetMessage_VehicleClass AquanetMessage::SHIP;
const AquanetMessage_VehicleClass AquanetMessage::VehicleClass_MIN;
const AquanetMessage_VehicleClass AquanetMessage::VehicleClass_MAX;
const int AquanetMessage::VehicleClass_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

// ===================================================================

void AquanetMessage::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int AquanetMessage::kRosMsgIdFieldNumber;
const int AquanetMessage::kXFieldNumber;
const int AquanetMessage::kYFieldNumber;
const int AquanetMessage::kZFieldNumber;
const int AquanetMessage::kBodyMessageFieldNumber;
const int AquanetMessage::kVehClassFieldNumber;
const int AquanetMessage::kBatteryOkFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

AquanetMessage::AquanetMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_aquanet_2emessage_2eproto::scc_info_AquanetMessage.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:AquanetMessage)
}
AquanetMessage::AquanetMessage(const AquanetMessage& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  body_message_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_body_message()) {
    body_message_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.body_message_);
  }
  ::memcpy(&x_, &from.x_,
    static_cast<size_t>(reinterpret_cast<char*>(&veh_class_) -
    reinterpret_cast<char*>(&x_)) + sizeof(veh_class_));
  // @@protoc_insertion_point(copy_constructor:AquanetMessage)
}

void AquanetMessage::SharedCtor() {
  body_message_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&x_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&battery_ok_) -
      reinterpret_cast<char*>(&x_)) + sizeof(battery_ok_));
  veh_class_ = 1;
}

AquanetMessage::~AquanetMessage() {
  // @@protoc_insertion_point(destructor:AquanetMessage)
  SharedDtor();
}

void AquanetMessage::SharedDtor() {
  body_message_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void AquanetMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* AquanetMessage::descriptor() {
  ::protobuf_aquanet_2emessage_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_aquanet_2emessage_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const AquanetMessage& AquanetMessage::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_aquanet_2emessage_2eproto::scc_info_AquanetMessage.base);
  return *internal_default_instance();
}


void AquanetMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:AquanetMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    body_message_.ClearNonDefaultToEmptyNoArena();
  }
  if (cached_has_bits & 126u) {
    ::memset(&x_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&battery_ok_) -
        reinterpret_cast<char*>(&x_)) + sizeof(battery_ok_));
    veh_class_ = 1;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool AquanetMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:AquanetMessage)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 ros_msg_id = 1 [(.dccl.field) = {
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_ros_msg_id();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &ros_msg_id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional double x = 2 [(.dccl.field) = {
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(17u /* 17 & 0xFF */)) {
          set_has_x();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &x_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional double y = 3 [(.dccl.field) = {
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(25u /* 25 & 0xFF */)) {
          set_has_y();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &y_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional double z = 4 [(.dccl.field) = {
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(33u /* 33 & 0xFF */)) {
          set_has_z();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &z_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string body_message = 5 [(.dccl.field) = {
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_body_message()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->body_message().data(), static_cast<int>(this->body_message().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "AquanetMessage.body_message");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .AquanetMessage.VehicleClass veh_class = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::AquanetMessage_VehicleClass_IsValid(value)) {
            set_veh_class(static_cast< ::AquanetMessage_VehicleClass >(value));
          } else {
            mutable_unknown_fields()->AddVarint(
                6, static_cast< ::google::protobuf::uint64>(value));
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bool battery_ok = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(56u /* 56 & 0xFF */)) {
          set_has_battery_ok();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &battery_ok_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:AquanetMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:AquanetMessage)
  return false;
#undef DO_
}

void AquanetMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:AquanetMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint32 ros_msg_id = 1 [(.dccl.field) = {
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->ros_msg_id(), output);
  }

  // optional double x = 2 [(.dccl.field) = {
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->x(), output);
  }

  // optional double y = 3 [(.dccl.field) = {
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(3, this->y(), output);
  }

  // optional double z = 4 [(.dccl.field) = {
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(4, this->z(), output);
  }

  // optional string body_message = 5 [(.dccl.field) = {
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->body_message().data(), static_cast<int>(this->body_message().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "AquanetMessage.body_message");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->body_message(), output);
  }

  // optional .AquanetMessage.VehicleClass veh_class = 6;
  if (cached_has_bits & 0x00000040u) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      6, this->veh_class(), output);
  }

  // optional bool battery_ok = 7;
  if (cached_has_bits & 0x00000020u) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->battery_ok(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:AquanetMessage)
}

::google::protobuf::uint8* AquanetMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:AquanetMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint32 ros_msg_id = 1 [(.dccl.field) = {
  if (cached_has_bits & 0x00000010u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->ros_msg_id(), target);
  }

  // optional double x = 2 [(.dccl.field) = {
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->x(), target);
  }

  // optional double y = 3 [(.dccl.field) = {
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, this->y(), target);
  }

  // optional double z = 4 [(.dccl.field) = {
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, this->z(), target);
  }

  // optional string body_message = 5 [(.dccl.field) = {
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->body_message().data(), static_cast<int>(this->body_message().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "AquanetMessage.body_message");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->body_message(), target);
  }

  // optional .AquanetMessage.VehicleClass veh_class = 6;
  if (cached_has_bits & 0x00000040u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      6, this->veh_class(), target);
  }

  // optional bool battery_ok = 7;
  if (cached_has_bits & 0x00000020u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(7, this->battery_ok(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:AquanetMessage)
  return target;
}

size_t AquanetMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:AquanetMessage)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // required uint32 ros_msg_id = 1 [(.dccl.field) = {
  if (has_ros_msg_id()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->ros_msg_id());
  }
  if (_has_bits_[0 / 32] & 15u) {
    // optional string body_message = 5 [(.dccl.field) = {
    if (has_body_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->body_message());
    }

    // optional double x = 2 [(.dccl.field) = {
    if (has_x()) {
      total_size += 1 + 8;
    }

    // optional double y = 3 [(.dccl.field) = {
    if (has_y()) {
      total_size += 1 + 8;
    }

    // optional double z = 4 [(.dccl.field) = {
    if (has_z()) {
      total_size += 1 + 8;
    }

  }
  if (_has_bits_[0 / 32] & 96u) {
    // optional bool battery_ok = 7;
    if (has_battery_ok()) {
      total_size += 1 + 1;
    }

    // optional .AquanetMessage.VehicleClass veh_class = 6;
    if (has_veh_class()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->veh_class());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void AquanetMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:AquanetMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const AquanetMessage* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const AquanetMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:AquanetMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:AquanetMessage)
    MergeFrom(*source);
  }
}

void AquanetMessage::MergeFrom(const AquanetMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:AquanetMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 127u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_body_message();
      body_message_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.body_message_);
    }
    if (cached_has_bits & 0x00000002u) {
      x_ = from.x_;
    }
    if (cached_has_bits & 0x00000004u) {
      y_ = from.y_;
    }
    if (cached_has_bits & 0x00000008u) {
      z_ = from.z_;
    }
    if (cached_has_bits & 0x00000010u) {
      ros_msg_id_ = from.ros_msg_id_;
    }
    if (cached_has_bits & 0x00000020u) {
      battery_ok_ = from.battery_ok_;
    }
    if (cached_has_bits & 0x00000040u) {
      veh_class_ = from.veh_class_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void AquanetMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:AquanetMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AquanetMessage::CopyFrom(const AquanetMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:AquanetMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AquanetMessage::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000010) != 0x00000010) return false;
  return true;
}

void AquanetMessage::Swap(AquanetMessage* other) {
  if (other == this) return;
  InternalSwap(other);
}
void AquanetMessage::InternalSwap(AquanetMessage* other) {
  using std::swap;
  body_message_.Swap(&other->body_message_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(x_, other->x_);
  swap(y_, other->y_);
  swap(z_, other->z_);
  swap(ros_msg_id_, other->ros_msg_id_);
  swap(battery_ok_, other->battery_ok_);
  swap(veh_class_, other->veh_class_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata AquanetMessage::GetMetadata() const {
  protobuf_aquanet_2emessage_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_aquanet_2emessage_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::AquanetMessage* Arena::CreateMaybeMessage< ::AquanetMessage >(Arena* arena) {
  return Arena::CreateInternal< ::AquanetMessage >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
