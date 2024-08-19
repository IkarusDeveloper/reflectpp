#ifndef INCLUDE_REFLECTPP_REFLECT_H
#define INCLUDE_REFLECTPP_REFLECT_H

#include "stdinclude.h"
#include "crc.h"

//// autodetect of macro args
#define REFL_EXPAND(X) X
#define REFL_MEMBER(type, name) type,name
#define REFL_CLASS_NAME(name) name
#define REFL_BASE_NAME(name) name

#define _REFL_CONCATENATE(x,y) x##y
#define REFL_CONCATENATE(x,y) _REFL_CONCATENATE(x, y)
#define _REFL_NARGS_IMPL( \
	X100, X99, X98, X97, X96, X95, X94, X93, X92, X91, X90, X89, X88, X87, X86, X85, X84, X83, X82, X81,     \
	X80, X79, X78, X77, X76, X75, X74, X73, X72, X71, X70, X69, X68, X67, X66, X65, X64, X63, X62, X61, X60, \
	X59, X58, X57, X56, X55, X54, X53, X52, X51, X50, X49, X48, X47, X46, X45, X44, X43, X42, X41, X40, X39, \
	X38, X37, X36, X35, X34, X33, X32, X31, X30, X29, X28, X27, X26, X25, X24, X23, X22, X21, X20, X19, X18, \
	X17, X16, X15, X14, X13, X12, X11, X10, X9, X8, X7, X6, X5, X4, X3, X2, X1, N, ...)                      \
	N
#define REFL_NARGS(...) \
	REFL_EXPAND(_REFL_NARGS_IMPL(__VA_ARGS__, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87,   \
									 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, \
									 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, \
									 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, \
									 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, \
									 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))

#define _REFL_MEMBER_2(type, name) type name{};
#define _REFL_MEMBER_4(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_6(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_8(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_10(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_12(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_14(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_16(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_18(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_20(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_22(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_24(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_26(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_28(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_30(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_32(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_34(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_36(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_38(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_40(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))
#define _REFL_MEMBER_42(type, name, ...) type name{}; REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(##__VA_ARGS__))

#define _REFL_TUPLE_TYPE_MEMBER_2(desc, type, name) desc type&
#define _REFL_TUPLE_TYPE_MEMBER_4(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_6(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_8(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_10(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_12(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_14(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_16(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_18(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_20(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_22(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_24(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_26(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_28(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_30(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_32(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_34(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_38(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_40(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_TYPE_MEMBER_42(desc, type, name, ...) desc type&, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))

#define _REFL_TUPLE_VALUE_MEMBER_2(desc, type, name) desc name
#define _REFL_TUPLE_VALUE_MEMBER_4(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_6(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_8(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_10(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_12(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_14(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_16(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_18(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_20(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_22(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_24(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_26(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_28(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_30(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_32(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_34(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_38(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_40(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))
#define _REFL_TUPLE_VALUE_MEMBER_42(desc, type, name, ...) desc name, REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(desc, ##__VA_ARGS__))

#define _REFL_CALL_VALUE_MEMBER_2( function, type, name) function(#name, name);
#define _REFL_CALL_VALUE_MEMBER_4( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_6( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_8( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_10( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_12( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_14( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_16( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_18( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_20( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_22( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_24( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_26( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_28( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_30( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_32( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_34( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_38( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_40( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))
#define _REFL_CALL_VALUE_MEMBER_42( function, type, name, ...) function(#name, name); REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))( function, ##__VA_ARGS__))

#define _REFL_NAME_GETTER(_name) \
	static constexpr std::string type_name(){ return #_name; }\
	constexpr std::string name() const { return #_name; }

#define _REFL_FALSE_INHERITANCE()\
	static constexpr bool is_inherited(){ return false; }
#define _REFL_TRUE_INHERITANCE(name, base)\
	static constexpr bool is_inherited(){ return true; }\
	using base_type = base;\
	name::base_type& base_object(){ return static_cast<name::base_type&>(*this); }\
	const name::base_type& base_object() const { return static_cast<const name::base_type&>(*this); }

// NO EXPANSIONS
#define REFL_CLASS(name, ...) \
	struct name : public refl::reflect_class {  \
		_REFL_FALSE_INHERITANCE()\
		_REFL_NAME_GETTER(name)\
		REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_NARGS(__VA_ARGS__))(__VA_ARGS__))\
	}
#define REFL_CLASS_DERIVED(name, base, ...)\
	struct name : public base {  \
		_REFL_TRUE_INHERITANCE(name, base)\
		_REFL_NAME_GETTER(name)\
		REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_NARGS(__VA_ARGS__))(__VA_ARGS__))\
	}


// SINGLE EXPANSION
#define REFL_CLASS_EXPAND1(expander, name, ...) struct name : public refl::reflect_class {  \
	_REFL_FALSE_INHERITANCE()\
	_REFL_NAME_GETTER(name)\
	REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(__VA_ARGS__))\
	expander(name, __VA_ARGS__)\
}
#define REFL_CLASS_DERIVED_EXPAND1(expander, name, base, ...) struct name : public base {  \
	_REFL_TRUE_INHERITANCE(name, base)\
	_REFL_NAME_GETTER(name)\
	REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(__VA_ARGS__))\
	expander(name, __VA_ARGS__)\
}


// 2 EXPANSIONS
#define REFL_CLASS_EXPAND2(expander1, expander2, name, ...) struct name : public refl::reflect_class {  \
	_REFL_FALSE_INHERITANCE()\
	_REFL_NAME_GETTER(name)\
	REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(__VA_ARGS__))\
	expander1(name, __VA_ARGS__)\
	expander2(name, __VA_ARGS__)\
}
#define REFL_CLASS_DERIVED_EXPAND2(expander1, expander2, name, base, ...) struct name : public base {  \
	_REFL_TRUE_INHERITANCE(name, base)\
	_REFL_NAME_GETTER(name)\
	REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(__VA_ARGS__))\
	expander1(name, __VA_ARGS__)\
	expander2(name, __VA_ARGS__)\
}



// 3 EXPANSIONS
#define REFL_CLASS_EXPAND3(expander1, expander2, expander3, name, ...) struct name : public refl::reflect_class {  \
	_REFL_FALSE_INHERITANCE()\
	_REFL_NAME_GETTER(name)\
	REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(__VA_ARGS__))\
	expander1(name, __VA_ARGS__)\
	expander2(name, __VA_ARGS__)\
	expander3(name, __VA_ARGS__)\
}
#define REFL_CLASS_DERIVED_EXPAND3(expander1, expander2, expander3, name, base, ...) struct name : public base {  \
	_REFL_TRUE_INHERITANCE(name, base)\
	_REFL_NAME_GETTER(name)\
	REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(__VA_ARGS__))\
	expander1(name, __VA_ARGS__)\
	expander2(name, __VA_ARGS__)\
	expander3(name, __VA_ARGS__)\
}



// 4 EXPANSIONS
#define REFL_CLASS_EXPAND4(expander1, expander2, expander3, expander4, name, ...) struct name : public refl::reflect_class {  \
	_REFL_FALSE_INHERITANCE()\
	_REFL_NAME_GETTER(name)\
	REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(__VA_ARGS__))\
	expander1(name, __VA_ARGS__)\
	expander2(name, __VA_ARGS__)\
	expander3(name, __VA_ARGS__)\
	expander4(name, __VA_ARGS__)\
}
#define REFL_CLASS_DERIVED_EXPAND4(expander1, expander2, expander3, expander4, name, base, ...) struct name : public base {  \
	_REFL_TRUE_INHERITANCE(name, base)\
	_REFL_NAME_GETTER(name)\
	REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(__VA_ARGS__))\
	expander1(name, __VA_ARGS__)\
	expander2(name, __VA_ARGS__)\
	expander3(name, __VA_ARGS__)\
	expander4(name, __VA_ARGS__)\
}



// 5 EXPANSIONS
#define REFL_CLASS_EXPAND5(expander1, expander2, expander3, expander4, expander5, name, ...) struct name : public refl::reflect_class {  \
	_REFL_FALSE_INHERITANCE()\
	_REFL_NAME_GETTER(name)\
	REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(__VA_ARGS__))\
	expander1(name, __VA_ARGS__)\
	expander2(name, __VA_ARGS__)\
	expander3(name, __VA_ARGS__)\
	expander4(name, __VA_ARGS__)\
	expander5(name, __VA_ARGS__)\
}
#define REFL_CLASS_DERIVED_EXPAND5(expander1, expander2, expander3, expander4, expander5, name, base, ...) struct name : public base {  \
	_REFL_TRUE_INHERITANCE(name, base)\
	_REFL_NAME_GETTER(name)\
	REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(__VA_ARGS__))\
	expander1(name, __VA_ARGS__)\
	expander2(name, __VA_ARGS__)\
	expander3(name, __VA_ARGS__)\
	expander4(name, __VA_ARGS__)\
	expander5(name, __VA_ARGS__)\
}

// 6 EXPANSIONS
#define REFL_CLASS_EXPAND6(expander1, expander2, expander3, expander4, expander5, expander6, name, ...) struct name : public refl::reflect_class {  \
	_REFL_FALSE_INHERITANCE()\
	_REFL_NAME_GETTER(name)\
	REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(__VA_ARGS__))\
	expander1(name, __VA_ARGS__)\
	expander2(name, __VA_ARGS__)\
	expander3(name, __VA_ARGS__)\
	expander4(name, __VA_ARGS__)\
	expander5(name, __VA_ARGS__)\
}
#define REFL_CLASS_DERIVED_EXPAND6(expander1, expander2, expander3, expander4, expander5, expander6, name, base, ...) struct name : public base {  \
	_REFL_TRUE_INHERITANCE(name, base)\
	_REFL_NAME_GETTER(name)\
	REFL_EXPAND(REFL_CONCATENATE(_REFL_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(__VA_ARGS__))\
	expander1(name, __VA_ARGS__)\
	expander2(name, __VA_ARGS__)\
	expander3(name, __VA_ARGS__)\
	expander4(name, __VA_ARGS__)\
	expander5(name, __VA_ARGS__)\
	expander6(name, __VA_ARGS__)\
}


#define REFL_EXPANDER_TUPLE_GETTER(name, ...)\
	template<class T = name, std::enable_if_t<!T::is_inherited(), int> = 0>\
	std::tuple<REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(, __VA_ARGS__))> reflectedValues() { \
		return {REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(, __VA_ARGS__))};\
	}\
	template<class T = name, std::enable_if_t<T::is_inherited(), int> = 0>\
	decltype(auto) reflectedValues() { \
		std::tuple<REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(, __VA_ARGS__))> values = \
			{REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(, __VA_ARGS__))};\
		auto& baseobj = static_cast<T::base_type&>(*this);\
		return std::tuple_cat(values, baseobj.reflectedValues()); \
	}\
	template<class T = name, std::enable_if_t<!T::is_inherited(), int> = 0>\
	std::tuple<REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(const , __VA_ARGS__))> reflectedValues() const { \
		return {REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(, __VA_ARGS__))};\
	}\
	template<class T = name, std::enable_if_t<T::is_inherited(), int> = 0>\
	decltype(auto) reflectedValues() const { \
		std::tuple<REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_TYPE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(const , __VA_ARGS__))> values = \
			{REFL_EXPAND(REFL_CONCATENATE(_REFL_TUPLE_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(, __VA_ARGS__))};\
		auto& baseobj = static_cast<const T::base_type&>(*this);\
		return std::tuple_cat(values, baseobj.reflectedValues()); \
	}

#define REFL_EXPANDER_SERIALIZABLE(name, ...) \
	template<class Serializer, class T = name, std::enable_if_t<T::is_inherited(), int> = 0> \
	void serialize(Serializer& serializer) const { \
		REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(serializer.put, __VA_ARGS__)) \
		auto& baseobj = static_cast<const T::base_type&>(*this);\
		baseobj.serialize(serializer);\
	}\
	template<class Serializer, class T = name, std::enable_if_t<!T::is_inherited(), int> = 0> \
	void serialize(Serializer& serializer) const{ \
		REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(serializer.put, __VA_ARGS__)) \
	}\
	template<class Deserialize> void deserialize(Deserialize& deserializer){ \
		REFL_EXPAND(REFL_CONCATENATE(_REFL_CALL_VALUE_MEMBER_, REFL_EXPAND(REFL_NARGS(__VA_ARGS__)))(deserializer.get, __VA_ARGS__)) \
	}

#define REFL_EXPANDER_CRCNAME32(name, ...)\
	static constexpr uint32_t type_crc(){ return refl::crc32(#name); }\
	constexpr uint32_t crc(){ return type_crc(); }

#define REFL_EXPANDER_CRCNAME16(name, ...)\
	static constexpr uint16_t type_crc(){ return refl::crc16(#name); }\
	constexpr uint16_t crc(){ return type_crc(); }


#define REFL_CLASS_SERIALIZABLE(name, ...) REFL_CLASS_EXPAND1(REFL_EXPANDER_SERIALIZABLE, name, __VA_ARGS__)
#define REFL_CLASS_TUPLED(name, ...) REFL_CLASS_EXPAND1(REFL_EXPANDER_TUPLE_GETTER, name, __VA_ARGS__)
#define REFL_CLASS_CRCNAME16(name, ...) REFL_CLASS_EXPAND1(REFL_EXPANDER_CRCNAME16, name, __VA_ARGS__)
#define REFL_CLASS_CRCNAME32(name, ...) REFL_CLASS_EXPAND1(REFL_EXPANDER_CRCNAME32, name, __VA_ARGS__)

#define REFL_CLASS_DERIVED_SERIALIZABLE(name, base, ...) REFL_CLASS_DERIVED_EXPAND1(REFL_EXPANDER_SERIALIZABLE, name, base, __VA_ARGS__)
#define REFL_CLASS_DERIVED_TUPLED(name, base, ...) REFL_CLASS_DERIVED_EXPAND1(REFL_EXPANDER_TUPLE_GETTER, name, base, __VA_ARGS__)
#define REFL_CLASS_DERIVED_CRCNAME16(name, base, ...) REFL_CLASS_DERIVED_EXPAND1(REFL_EXPANDER_CRCNAME16, name, base, __VA_ARGS__)
#define REFL_CLASS_DERIVED_CRCNAME32(name, base, ...) REFL_CLASS_DERIVED_EXPAND1(REFL_EXPANDER_CRCNAME32, name, base, __VA_ARGS__)

namespace refl
{
	struct reflect_class {};
}

#endif //INCLUDE_REFLECTPP_REFLECT_H