// FreeTTCN is a free compiler and execution environment for TTCN-3 language.
//
// Copyright (C) 2016 Mateusz Pusz
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "types.h"

class TciType {
public:
  virtual ~TciType();
  virtual const TciModuleId& getDefiningModule() const = 0;
  virtual const Tstring& getName() const = 0;
  virtual const TciTypeClass& getTypeClass() const = 0;
  virtual const Tstring& getTypeEncoding() const = 0;
  virtual const Tstring& getTypeEncodingVariant() const = 0;
  virtual const std::vector<Tstring*>& getTypeExtension() const = 0;
  virtual TciValue* newInstance() const = 0;
  virtual TciValue* parseValue(const Tstring& val) const = 0;
  virtual Tboolean operator==(const TciType& typ) const = 0;
  virtual TciType* clone() const = 0;
  virtual Tboolean operator<(const TciType& typ) const = 0;
};

class TciValue {
public:
  virtual ~TciValue();
  virtual const TciType& getType() const = 0;
  virtual const Tstring& getValueEncoding() const = 0;
  virtual const Tstring& getValueEncodingVariant() const = 0;
  virtual Tboolean notPresent() const = 0;
  virtual Tboolean isMatchingSymbol() const = 0;
  virtual const Tstring& valueToString() const = 0;
  virtual Tboolean isLazy() const = 0;
  virtual Tboolean isFuzzy() const = 0;
  virtual Tboolean isEvaluated() const = 0;
  virtual LengthRestriction* getLengthRestriction() const = 0;
  virtual LengthRestriction* newLengthRestriction() const = 0;
  virtual void setLengthRestriction(const LengthRestriction* p_restriction) = 0;
  virtual Tboolean isIfPresentEnabled() const = 0;
  virtual void setIfPresentEnabled(Tboolean p_enabled) = 0;
  virtual Tboolean operator==(const TciValue& p_val) const = 0;
  virtual TciValue* clone() const = 0;
  virtual Tboolean operator<(const TciValue& p_val) const = 0;
};

class IntegerValue : public virtual TciValue {
public:
  virtual ~IntegerValue();
  virtual Tinteger getInt() const = 0;
  virtual void setInt(Tinteger p_value) = 0;
  virtual Tboolean operator==(const IntegerValue& p_intVal) const = 0;
  virtual IntegerValue* clone() const = 0;
  virtual Tboolean operator<(const IntegerValue& p_intVal) const = 0;
};

class FloatValue : public virtual TciValue {
public:
  virtual ~FloatValue();
  virtual Tfloat getFloat() const = 0;
  virtual void setFloat(Tfloat p_floatValue) = 0;
  virtual Tboolean operator==(const FloatValue& p_floatVal) const = 0;
  virtual FloatValue* clone() const = 0;
  virtual Tboolean operator<(const FloatValue& p_floatVal) const = 0;
};

class BooleanValue : public virtual TciValue {
public:
  virtual ~BooleanValue();
  virtual Tboolean getBoolean() const = 0;
  virtual void setBoolean(Tboolean p_booleanValue) = 0;
  virtual Tboolean operator==(const BooleanValue& p_booleanVal) const = 0;
  virtual BooleanValue* clone() const = 0;
  virtual Tboolean operator<(const BooleanValue& p_booleanVal) const = 0;
};

class CharstringValue : public virtual TciValue {
public:
  virtual ~CharstringValue();
  virtual char getChar(Tindex p_position) const = 0;
  virtual Tsize getLength() const = 0;
  virtual const Tstring& getString() const = 0;
  virtual void setChar(Tsize p_position, char p_char) = 0;
  virtual void setLength(Tsize p_length) = 0;
  virtual void setString(const Tstring& p_charValue) = 0;
  virtual Tboolean operator==(const CharstringValue& p_charStr) const = 0;
  virtual CharstringValue* clone() const = 0;
  virtual Tboolean operator<(const CharstringValue& p_charStr) const = 0;
};

class UniversalCharstringValue : public virtual TciValue {
public:
  virtual ~UniversalCharstringValue();
  virtual wchar_t getChar(Tindex p_position) const = 0;
  virtual Tsize getLength() const = 0;
  virtual const TuniversalString& getString() const = 0;
  virtual void setChar(Tindex p_position, const wchar_t p_ucValue) = 0;
  virtual void setLength(Tsize p_length) = 0;
  virtual void setString(const TuniversalString& p_ucsValue) = 0;
  virtual Tboolean operator==(const UniversalCharstringValue& p_uniCharstr) const = 0;
  virtual UniversalCharstringValue* clone() const = 0;
  virtual Tboolean operator<(const UniversalCharstringValue& p_uniCharstr) const = 0;
};

class BitstringValue : public virtual TciValue {
public:
  virtual ~BitstringValue();
  virtual Tbit getBit(Tindex p_position) const = 0;
  virtual Tsize getLength() const = 0;
  virtual const Tstring& getString() const = 0;
  virtual void setBit(Tindex p_position, Tbit p_bsValue) = 0;
  virtual void setLength(Tindex p_new_length) = 0;
  virtual void setString(const Tstring& p_bsValue) = 0;
  virtual Tboolean isMatchingAt(Tindex p_position) const = 0;
  virtual MatchingMechanism& getMatchingAt(Tindex p_position) const = 0;
  virtual void setMatchingAt(Tindex p_position, MatchingMechanism& p_template) = 0;
  virtual Tboolean operator==(const BitstringValue& p_bitStr) const = 0;
  virtual BitstringValue* clone() const = 0;
  virtual Tboolean operator<(const BitstringValue& p_bitStr) const = 0;
};

class OctetstringValue : public virtual TciValue {
public:
  virtual ~OctetstringValue();
  virtual Tsize getLength() const = 0;
  virtual const Tchar getOctet(Tindex p_position) const = 0;
  virtual const Tstring& getString() const = 0;
  virtual void setLength(Tsize p_length) = 0;
  virtual void setOctet(Tindex p_position, Tchar p_ochar) = 0;
  virtual void setString(const Tstring& p_osValue) = 0;
  virtual Tboolean isMatchingAt(Tindex p_position) const = 0;
  virtual MatchingMechanism& getMatchingAt(Tindex p_position) const = 0;
  virtual void setMatchingAt(Tindex p_position, MatchingMechanism& p_template) = 0;
  virtual Tboolean operator==(const OctetstringValue& p_octStr) const = 0;
  virtual OctetstringValue* clone() const = 0;
  virtual Tboolean operator<(const OctetstringValue& p_octStr) const = 0;
};

class HexstringValue : public virtual TciValue {
public:
  virtual ~HexstringValue();
  virtual Tchar getHex(Tindex p_position) const = 0;
  virtual Tsize getLength() const = 0;
  virtual const Tstring& getString() const = 0;
  virtual void setHex(Tindex p_position, Tchar p_hcValue) = 0;
  virtual void setLength(Tsize p_length) = 0;
  virtual void setString(const Tstring& p_hsValue) = 0;
  virtual Tboolean isMatchingAt(Tindex p_position) const = 0;
  virtual MatchingMechanism& getMatchingAt(Tindex p_position) const = 0;
  virtual void setMatchingAt(Tindex p_position, MatchingMechanism& p_template) = 0;
  virtual Tboolean operator==(const HexstringValue& p_hexStr) const = 0;
  virtual HexstringValue* clone() const = 0;
  virtual Tboolean operator<(const HexstringValue& p_hexStr) const = 0;
};

class RecordValue : public virtual TciValue {
public:
  virtual ~RecordValue();
  virtual TciValue& getField(const Tstring& p_field_name) = 0;
  virtual void setField(const Tstring& p_field_name, const TciValue& p_new_value) = 0;
  virtual const std::vector<Tstring*>& getFieldNames() const = 0;
  virtual void setFieldOmitted(const Tstring& p_fieldName) = 0;
  virtual Tboolean operator==(const RecordValue& p_rec) const = 0;
  virtual RecordValue* clone() const = 0;
  virtual Tboolean operator<(const RecordValue& p_rec) const = 0;
};

class RecordOfValue : public virtual TciValue {
public:
  virtual ~RecordOfValue();
  virtual TciValue& getField(Tindex p_position) = 0;
  virtual void setField(Tindex p_position, const TciValue& p_value) = 0;
  virtual void appendField(const TciValue& p_value) = 0;
  virtual const TciType& getElementType() const = 0;
  virtual Tsize getLength() const = 0;
  virtual void setLength(Tsize p_length) = 0;
  virtual Tindex getOffset() const = 0;
  virtual Tsize getPermutationCount() const = 0;
  virtual Permutation& getPermutation(Tindex p_position) = 0;
  virtual Permutation* newPermutation(Tindex p_position) = 0;
  virtual void definePermutation(const Permutation& permutation) = 0;
  virtual void removePermutation(Tindex p_position) = 0;
  virtual void clearPermutations() = 0;
  virtual Tboolean operator==(const RecordOfValue& p_recOf) const = 0;
  virtual RecordOfValue* clone() const = 0;
  virtual Tboolean operator<(const RecordOfValue& p_recOf) const = 0;
};

class UnionValue : public virtual TciValue {
public:
  virtual ~UnionValue() virtual void setVariant(const Tstring& p_variantName, const TciValue& p_value) = 0;
  virtual TciValue& getVariant(const Tstring& p_variantName) = 0;
  virtual const Tstring& getPresentVariantName() const = 0;
  virtual const std::set<Tstring*>& getVariantNames() const = 0;
  virtual Tboolean operator==(const UnionValue& p_unionVal) const = 0;
  virtual UnionValue* clone() const = 0;
  virtual Tboolean operator<(const UnionValue& p_unionVal) const = 0;
};

class EnumeratedValue : public virtual TciValue {
public:
  virtual ~EnumeratedValue();
  virtual const Tstring& getEnum() const = 0;
  virtual void setEnum(const Tstring& p_value) = 0;
  virtual Tinteger getInt() const = 0;
  virtual void setInt(Tinteger p_int);
  virtual Tboolean operator==(const EnumeratedValue& p_enumVal) const = 0;
  virtual EnumeratedValue* clone() const = 0;
  virtual Tboolean operator<(const EnumeratedValue& p_enumVal) const = 0;
};

class VerdictValue : public virtual TciValue {
public:
  virtual ~VerdictValue();
  virtual const VerdictValueEnum& getVerdict() const = 0;
  virtual void setVerdict(const VerdictValueEnum& p_enum) = 0;
  virtual Tboolean operator==(const VerdictValue& p_verdictVal) const = 0;
  virtual VerdictValue* clone() const = 0;
  virtual Tboolean operator<(const VerdictValue& p_verdictVal) const = 0;
};

typedef enum { NONE = 0, PASS = 1, FAIL = 2, INCONC = 3, ERROR = 4, USER_ERROR = 5 } VerdictValueEnum;

class AddressValue {
public:
  virtual ~AddressValue();
  virtual TciValue& getAddress() = 0;
  virtual void setAddress(const TciValue& T) = 0;
  virtual Tboolean operator==(const AddressValue& p_addr) const = 0;
  virtual AddressValue* cloneAddressValue() const = 0;
  virtual Tboolean operator<(const AddressValue& p_addr) const = 0;
};

class MatchingMechanism : public virtual TciValue {
public:
  virtual ~MatchingMechanism();
  virtual TciMatchingType getMatchingType() const = 0;
  virtual Tboolean operator==(const MatchingMechanism& p_template) const = 0;
  virtual MatchingMechanism* clone() const = 0;
  virtual Tboolean operator<(const MatchingMechanism& p_template) const = 0;
};

class MatchingList : public virtual MatchingMechanism {
public:
  virtual ~MatchingList();
  virtual Tsize size() const = 0;
  virtual Value get(Tindex p_position) const = 0;
  virtual void add(TciValue p_val) = 0;
  virtual void remove(Tindex p_position) = 0;
  virtual void clear() = 0;
  virtual Tboolean operator==(const MatchingList& p_list) const = 0;
  virtual MatchingList* clone() const = 0;
  virtual Tboolean operator<(const MatchingList& p_list) const = 0;
};

class ValueRange : public virtual MatchingMechanism {
public:
  virtual ~ValueRange();
  virtual RangeBoundary& getLowerBoundary() = 0;
  virtual RangeBoundary& getUpperBoundary() = 0;
  virtual void setLowerBoundary(const RangeBoundary& p_boundary) = 0;
  virtual void setUpperBoundary(const RangeBoundary& p_boundary) = 0;
  virtual Tboolean operator==(const ValueRange& p_range) const = 0;
  virtual ValueRange* clone() const = 0;
  virtual Tboolean operator<(const ValueRange& p_range) const = 0;
};

class CharacterPattern : public virtual MatchingMechanism {
public:
  virtual ~CharacterPattern();
  virtual TciValue& getPatternString() = 0;
  virtual void setPatternString(const TciValue& p_string) = 0;
  virtual Tboolean operator==(const CharacterPattern& p_pattern) const = 0;
  virtual CharacterPattern* clone() const = 0;
  virtual Tboolean operator<(const CharacterPattern& p_pattern) const = 0;
};

class MatchDecodedContent : public virtual MatchingMechanism {
public:
  virtual ~MatchDecodedContent();
  virtual TciValue& getContent() = 0;
  virtual void setContent(const TciValue& p_content) = 0;
  virtual Tboolean operator==(const MatchDecodedContent& p_content) const = 0;
  virtual MatchDecodedContent* clone() const = 0;
  virtual Tboolean operator<(const MatchDecodedContent& p_content) const = 0;
};
