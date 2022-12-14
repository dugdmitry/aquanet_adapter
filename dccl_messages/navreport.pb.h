// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: navreport.proto

#ifndef PROTOBUF_navreport_2eproto__INCLUDED
#define PROTOBUF_navreport_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "dccl/option_extensions.pb.h"
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_navreport_2eproto();
void protobuf_AssignDesc_navreport_2eproto();
void protobuf_ShutdownFile_navreport_2eproto();

class NavigationReport;

enum NavigationReport_VehicleClass {
  NavigationReport_VehicleClass_AUV = 1,
  NavigationReport_VehicleClass_USV = 2,
  NavigationReport_VehicleClass_SHIP = 3
};
bool NavigationReport_VehicleClass_IsValid(int value);
const NavigationReport_VehicleClass NavigationReport_VehicleClass_VehicleClass_MIN = NavigationReport_VehicleClass_AUV;
const NavigationReport_VehicleClass NavigationReport_VehicleClass_VehicleClass_MAX = NavigationReport_VehicleClass_SHIP;
const int NavigationReport_VehicleClass_VehicleClass_ARRAYSIZE = NavigationReport_VehicleClass_VehicleClass_MAX + 1;

const ::google::protobuf::EnumDescriptor* NavigationReport_VehicleClass_descriptor();
inline const ::std::string& NavigationReport_VehicleClass_Name(NavigationReport_VehicleClass value) {
  return ::google::protobuf::internal::NameOfEnum(
    NavigationReport_VehicleClass_descriptor(), value);
}
inline bool NavigationReport_VehicleClass_Parse(
    const ::std::string& name, NavigationReport_VehicleClass* value) {
  return ::google::protobuf::internal::ParseNamedEnum<NavigationReport_VehicleClass>(
    NavigationReport_VehicleClass_descriptor(), name, value);
}
// ===================================================================

class NavigationReport : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NavigationReport) */ {
 public:
  NavigationReport();
  virtual ~NavigationReport();

  NavigationReport(const NavigationReport& from);

  inline NavigationReport& operator=(const NavigationReport& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NavigationReport& default_instance();

  void Swap(NavigationReport* other);

  // implements Message ----------------------------------------------

  inline NavigationReport* New() const { return New(NULL); }

  NavigationReport* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NavigationReport& from);
  void MergeFrom(const NavigationReport& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(NavigationReport* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef NavigationReport_VehicleClass VehicleClass;
  static const VehicleClass AUV =
    NavigationReport_VehicleClass_AUV;
  static const VehicleClass USV =
    NavigationReport_VehicleClass_USV;
  static const VehicleClass SHIP =
    NavigationReport_VehicleClass_SHIP;
  static inline bool VehicleClass_IsValid(int value) {
    return NavigationReport_VehicleClass_IsValid(value);
  }
  static const VehicleClass VehicleClass_MIN =
    NavigationReport_VehicleClass_VehicleClass_MIN;
  static const VehicleClass VehicleClass_MAX =
    NavigationReport_VehicleClass_VehicleClass_MAX;
  static const int VehicleClass_ARRAYSIZE =
    NavigationReport_VehicleClass_VehicleClass_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  VehicleClass_descriptor() {
    return NavigationReport_VehicleClass_descriptor();
  }
  static inline const ::std::string& VehicleClass_Name(VehicleClass value) {
    return NavigationReport_VehicleClass_Name(value);
  }
  static inline bool VehicleClass_Parse(const ::std::string& name,
      VehicleClass* value) {
    return NavigationReport_VehicleClass_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required double x = 1;
  bool has_x() const;
  void clear_x();
  static const int kXFieldNumber = 1;
  double x() const;
  void set_x(double value);

  // required double y = 2;
  bool has_y() const;
  void clear_y();
  static const int kYFieldNumber = 2;
  double y() const;
  void set_y(double value);

  // required double z = 3;
  bool has_z() const;
  void clear_z();
  static const int kZFieldNumber = 3;
  double z() const;
  void set_z(double value);

  // optional .NavigationReport.VehicleClass veh_class = 4;
  bool has_veh_class() const;
  void clear_veh_class();
  static const int kVehClassFieldNumber = 4;
  ::NavigationReport_VehicleClass veh_class() const;
  void set_veh_class(::NavigationReport_VehicleClass value);

  // optional bool battery_ok = 5;
  bool has_battery_ok() const;
  void clear_battery_ok();
  static const int kBatteryOkFieldNumber = 5;
  bool battery_ok() const;
  void set_battery_ok(bool value);

  // @@protoc_insertion_point(class_scope:NavigationReport)
 private:
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();
  inline void set_has_z();
  inline void clear_has_z();
  inline void set_has_veh_class();
  inline void clear_has_veh_class();
  inline void set_has_battery_ok();
  inline void clear_has_battery_ok();

  // helper for ByteSize()
  int RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  double x_;
  double y_;
  double z_;
  int veh_class_;
  bool battery_ok_;
  friend void  protobuf_AddDesc_navreport_2eproto();
  friend void protobuf_AssignDesc_navreport_2eproto();
  friend void protobuf_ShutdownFile_navreport_2eproto();

  void InitAsDefaultInstance();
  static NavigationReport* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// NavigationReport

// required double x = 1;
inline bool NavigationReport::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NavigationReport::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NavigationReport::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NavigationReport::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline double NavigationReport::x() const {
  // @@protoc_insertion_point(field_get:NavigationReport.x)
  return x_;
}
inline void NavigationReport::set_x(double value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:NavigationReport.x)
}

// required double y = 2;
inline bool NavigationReport::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void NavigationReport::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void NavigationReport::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void NavigationReport::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline double NavigationReport::y() const {
  // @@protoc_insertion_point(field_get:NavigationReport.y)
  return y_;
}
inline void NavigationReport::set_y(double value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:NavigationReport.y)
}

// required double z = 3;
inline bool NavigationReport::has_z() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void NavigationReport::set_has_z() {
  _has_bits_[0] |= 0x00000004u;
}
inline void NavigationReport::clear_has_z() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void NavigationReport::clear_z() {
  z_ = 0;
  clear_has_z();
}
inline double NavigationReport::z() const {
  // @@protoc_insertion_point(field_get:NavigationReport.z)
  return z_;
}
inline void NavigationReport::set_z(double value) {
  set_has_z();
  z_ = value;
  // @@protoc_insertion_point(field_set:NavigationReport.z)
}

// optional .NavigationReport.VehicleClass veh_class = 4;
inline bool NavigationReport::has_veh_class() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void NavigationReport::set_has_veh_class() {
  _has_bits_[0] |= 0x00000008u;
}
inline void NavigationReport::clear_has_veh_class() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void NavigationReport::clear_veh_class() {
  veh_class_ = 1;
  clear_has_veh_class();
}
inline ::NavigationReport_VehicleClass NavigationReport::veh_class() const {
  // @@protoc_insertion_point(field_get:NavigationReport.veh_class)
  return static_cast< ::NavigationReport_VehicleClass >(veh_class_);
}
inline void NavigationReport::set_veh_class(::NavigationReport_VehicleClass value) {
  assert(::NavigationReport_VehicleClass_IsValid(value));
  set_has_veh_class();
  veh_class_ = value;
  // @@protoc_insertion_point(field_set:NavigationReport.veh_class)
}

// optional bool battery_ok = 5;
inline bool NavigationReport::has_battery_ok() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void NavigationReport::set_has_battery_ok() {
  _has_bits_[0] |= 0x00000010u;
}
inline void NavigationReport::clear_has_battery_ok() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void NavigationReport::clear_battery_ok() {
  battery_ok_ = false;
  clear_has_battery_ok();
}
inline bool NavigationReport::battery_ok() const {
  // @@protoc_insertion_point(field_get:NavigationReport.battery_ok)
  return battery_ok_;
}
inline void NavigationReport::set_battery_ok(bool value) {
  set_has_battery_ok();
  battery_ok_ = value;
  // @@protoc_insertion_point(field_set:NavigationReport.battery_ok)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::NavigationReport_VehicleClass> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NavigationReport_VehicleClass>() {
  return ::NavigationReport_VehicleClass_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_navreport_2eproto__INCLUDED
