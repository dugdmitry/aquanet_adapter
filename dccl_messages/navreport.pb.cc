// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: navreport.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "navreport.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* NavigationReport_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  NavigationReport_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* NavigationReport_VehicleClass_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_navreport_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_navreport_2eproto() {
  protobuf_AddDesc_navreport_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "navreport.proto");
  GOOGLE_CHECK(file != NULL);
  NavigationReport_descriptor_ = file->message_type(0);
  static const int NavigationReport_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NavigationReport, x_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NavigationReport, y_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NavigationReport, z_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NavigationReport, veh_class_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NavigationReport, battery_ok_),
  };
  NavigationReport_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      NavigationReport_descriptor_,
      NavigationReport::default_instance_,
      NavigationReport_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NavigationReport, _has_bits_[0]),
      -1,
      -1,
      sizeof(NavigationReport),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NavigationReport, _internal_metadata_),
      -1);
  NavigationReport_VehicleClass_descriptor_ = NavigationReport_descriptor_->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_navreport_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      NavigationReport_descriptor_, &NavigationReport::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_navreport_2eproto() {
  delete NavigationReport::default_instance_;
  delete NavigationReport_reflection_;
}

void protobuf_AddDesc_navreport_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_navreport_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::dccl::protobuf_AddDesc_dccl_2foption_5fextensions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017navreport.proto\032\034dccl/option_extension"
    "s.proto\"\374\001\n\020NavigationReport\022\"\n\001x\030\001 \002(\001B"
    "\027\242\?\024 \001)\000\000\000\000\000\210\303\3001\000\000\000\000\000\210\303@\022\"\n\001y\030\002 \002(\001B\027\242\?\024"
    " \001)\000\000\000\000\000\210\303\3001\000\000\000\000\000\210\303@\022\"\n\001z\030\003 \002(\001B\027\242\?\024 \000)\000"
    "\000\000\000\000\210\263\3001\000\000\000\000\000\000\000\000\0221\n\tveh_class\030\004 \001(\0162\036.Na"
    "vigationReport.VehicleClass\022\022\n\nbattery_o"
    "k\030\005 \001(\010\"*\n\014VehicleClass\022\007\n\003AUV\020\001\022\007\n\003USV\020"
    "\002\022\010\n\004SHIP\020\003:\t\242\?\006\010|\020 (\003", 302);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "navreport.proto", &protobuf_RegisterTypes);
  NavigationReport::default_instance_ = new NavigationReport();
  NavigationReport::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_navreport_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_navreport_2eproto {
  StaticDescriptorInitializer_navreport_2eproto() {
    protobuf_AddDesc_navreport_2eproto();
  }
} static_descriptor_initializer_navreport_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* NavigationReport_VehicleClass_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return NavigationReport_VehicleClass_descriptor_;
}
bool NavigationReport_VehicleClass_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const NavigationReport_VehicleClass NavigationReport::AUV;
const NavigationReport_VehicleClass NavigationReport::USV;
const NavigationReport_VehicleClass NavigationReport::SHIP;
const NavigationReport_VehicleClass NavigationReport::VehicleClass_MIN;
const NavigationReport_VehicleClass NavigationReport::VehicleClass_MAX;
const int NavigationReport::VehicleClass_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int NavigationReport::kXFieldNumber;
const int NavigationReport::kYFieldNumber;
const int NavigationReport::kZFieldNumber;
const int NavigationReport::kVehClassFieldNumber;
const int NavigationReport::kBatteryOkFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

NavigationReport::NavigationReport()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:NavigationReport)
}

void NavigationReport::InitAsDefaultInstance() {
}

NavigationReport::NavigationReport(const NavigationReport& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:NavigationReport)
}

void NavigationReport::SharedCtor() {
  _cached_size_ = 0;
  x_ = 0;
  y_ = 0;
  z_ = 0;
  veh_class_ = 1;
  battery_ok_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

NavigationReport::~NavigationReport() {
  // @@protoc_insertion_point(destructor:NavigationReport)
  SharedDtor();
}

void NavigationReport::SharedDtor() {
  if (this != default_instance_) {
  }
}

void NavigationReport::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* NavigationReport::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return NavigationReport_descriptor_;
}

const NavigationReport& NavigationReport::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_navreport_2eproto();
  return *default_instance_;
}

NavigationReport* NavigationReport::default_instance_ = NULL;

NavigationReport* NavigationReport::New(::google::protobuf::Arena* arena) const {
  NavigationReport* n = new NavigationReport;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void NavigationReport::Clear() {
// @@protoc_insertion_point(message_clear_start:NavigationReport)
#if defined(__clang__)
#define ZR_HELPER_(f) \
  _Pragma("clang diagnostic push") \
  _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") \
  __builtin_offsetof(NavigationReport, f) \
  _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<NavigationReport*>(16)->f)
#endif

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  if (_has_bits_[0 / 32] & 31u) {
    ZR_(x_, z_);
    veh_class_ = 1;
    battery_ok_ = false;
  }

#undef ZR_HELPER_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool NavigationReport::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:NavigationReport)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required double x = 1;
      case 1: {
        if (tag == 9) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &x_)));
          set_has_x();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(17)) goto parse_y;
        break;
      }

      // required double y = 2;
      case 2: {
        if (tag == 17) {
         parse_y:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &y_)));
          set_has_y();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(25)) goto parse_z;
        break;
      }

      // required double z = 3;
      case 3: {
        if (tag == 25) {
         parse_z:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &z_)));
          set_has_z();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_veh_class;
        break;
      }

      // optional .NavigationReport.VehicleClass veh_class = 4;
      case 4: {
        if (tag == 32) {
         parse_veh_class:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::NavigationReport_VehicleClass_IsValid(value)) {
            set_veh_class(static_cast< ::NavigationReport_VehicleClass >(value));
          } else {
            mutable_unknown_fields()->AddVarint(4, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_battery_ok;
        break;
      }

      // optional bool battery_ok = 5;
      case 5: {
        if (tag == 40) {
         parse_battery_ok:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &battery_ok_)));
          set_has_battery_ok();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:NavigationReport)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:NavigationReport)
  return false;
#undef DO_
}

void NavigationReport::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:NavigationReport)
  // required double x = 1;
  if (has_x()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->x(), output);
  }

  // required double y = 2;
  if (has_y()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->y(), output);
  }

  // required double z = 3;
  if (has_z()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(3, this->z(), output);
  }

  // optional .NavigationReport.VehicleClass veh_class = 4;
  if (has_veh_class()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      4, this->veh_class(), output);
  }

  // optional bool battery_ok = 5;
  if (has_battery_ok()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->battery_ok(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:NavigationReport)
}

::google::protobuf::uint8* NavigationReport::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:NavigationReport)
  // required double x = 1;
  if (has_x()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->x(), target);
  }

  // required double y = 2;
  if (has_y()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->y(), target);
  }

  // required double z = 3;
  if (has_z()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, this->z(), target);
  }

  // optional .NavigationReport.VehicleClass veh_class = 4;
  if (has_veh_class()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      4, this->veh_class(), target);
  }

  // optional bool battery_ok = 5;
  if (has_battery_ok()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->battery_ok(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:NavigationReport)
  return target;
}

int NavigationReport::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:NavigationReport)
  int total_size = 0;

  if (has_x()) {
    // required double x = 1;
    total_size += 1 + 8;
  }

  if (has_y()) {
    // required double y = 2;
    total_size += 1 + 8;
  }

  if (has_z()) {
    // required double z = 3;
    total_size += 1 + 8;
  }

  return total_size;
}
int NavigationReport::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:NavigationReport)
  int total_size = 0;

  if (((_has_bits_[0] & 0x00000007) ^ 0x00000007) == 0) {  // All required fields are present.
    // required double x = 1;
    total_size += 1 + 8;

    // required double y = 2;
    total_size += 1 + 8;

    // required double z = 3;
    total_size += 1 + 8;

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  if (_has_bits_[3 / 32] & 24u) {
    // optional .NavigationReport.VehicleClass veh_class = 4;
    if (has_veh_class()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->veh_class());
    }

    // optional bool battery_ok = 5;
    if (has_battery_ok()) {
      total_size += 1 + 1;
    }

  }
  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void NavigationReport::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:NavigationReport)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const NavigationReport* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const NavigationReport>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:NavigationReport)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:NavigationReport)
    MergeFrom(*source);
  }
}

void NavigationReport::MergeFrom(const NavigationReport& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:NavigationReport)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_x()) {
      set_x(from.x());
    }
    if (from.has_y()) {
      set_y(from.y());
    }
    if (from.has_z()) {
      set_z(from.z());
    }
    if (from.has_veh_class()) {
      set_veh_class(from.veh_class());
    }
    if (from.has_battery_ok()) {
      set_battery_ok(from.battery_ok());
    }
  }
  if (from._internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->MergeFrom(from.unknown_fields());
  }
}

void NavigationReport::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:NavigationReport)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NavigationReport::CopyFrom(const NavigationReport& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:NavigationReport)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NavigationReport::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void NavigationReport::Swap(NavigationReport* other) {
  if (other == this) return;
  InternalSwap(other);
}
void NavigationReport::InternalSwap(NavigationReport* other) {
  std::swap(x_, other->x_);
  std::swap(y_, other->y_);
  std::swap(z_, other->z_);
  std::swap(veh_class_, other->veh_class_);
  std::swap(battery_ok_, other->battery_ok_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata NavigationReport::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = NavigationReport_descriptor_;
  metadata.reflection = NavigationReport_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// NavigationReport

// required double x = 1;
bool NavigationReport::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void NavigationReport::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
void NavigationReport::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
void NavigationReport::clear_x() {
  x_ = 0;
  clear_has_x();
}
 double NavigationReport::x() const {
  // @@protoc_insertion_point(field_get:NavigationReport.x)
  return x_;
}
 void NavigationReport::set_x(double value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:NavigationReport.x)
}

// required double y = 2;
bool NavigationReport::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void NavigationReport::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
void NavigationReport::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
void NavigationReport::clear_y() {
  y_ = 0;
  clear_has_y();
}
 double NavigationReport::y() const {
  // @@protoc_insertion_point(field_get:NavigationReport.y)
  return y_;
}
 void NavigationReport::set_y(double value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:NavigationReport.y)
}

// required double z = 3;
bool NavigationReport::has_z() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
void NavigationReport::set_has_z() {
  _has_bits_[0] |= 0x00000004u;
}
void NavigationReport::clear_has_z() {
  _has_bits_[0] &= ~0x00000004u;
}
void NavigationReport::clear_z() {
  z_ = 0;
  clear_has_z();
}
 double NavigationReport::z() const {
  // @@protoc_insertion_point(field_get:NavigationReport.z)
  return z_;
}
 void NavigationReport::set_z(double value) {
  set_has_z();
  z_ = value;
  // @@protoc_insertion_point(field_set:NavigationReport.z)
}

// optional .NavigationReport.VehicleClass veh_class = 4;
bool NavigationReport::has_veh_class() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
void NavigationReport::set_has_veh_class() {
  _has_bits_[0] |= 0x00000008u;
}
void NavigationReport::clear_has_veh_class() {
  _has_bits_[0] &= ~0x00000008u;
}
void NavigationReport::clear_veh_class() {
  veh_class_ = 1;
  clear_has_veh_class();
}
 ::NavigationReport_VehicleClass NavigationReport::veh_class() const {
  // @@protoc_insertion_point(field_get:NavigationReport.veh_class)
  return static_cast< ::NavigationReport_VehicleClass >(veh_class_);
}
 void NavigationReport::set_veh_class(::NavigationReport_VehicleClass value) {
  assert(::NavigationReport_VehicleClass_IsValid(value));
  set_has_veh_class();
  veh_class_ = value;
  // @@protoc_insertion_point(field_set:NavigationReport.veh_class)
}

// optional bool battery_ok = 5;
bool NavigationReport::has_battery_ok() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
void NavigationReport::set_has_battery_ok() {
  _has_bits_[0] |= 0x00000010u;
}
void NavigationReport::clear_has_battery_ok() {
  _has_bits_[0] &= ~0x00000010u;
}
void NavigationReport::clear_battery_ok() {
  battery_ok_ = false;
  clear_has_battery_ok();
}
 bool NavigationReport::battery_ok() const {
  // @@protoc_insertion_point(field_get:NavigationReport.battery_ok)
  return battery_ok_;
}
 void NavigationReport::set_battery_ok(bool value) {
  set_has_battery_ok();
  battery_ok_ = value;
  // @@protoc_insertion_point(field_set:NavigationReport.battery_ok)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
