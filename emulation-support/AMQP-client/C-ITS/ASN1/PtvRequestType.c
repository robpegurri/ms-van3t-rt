/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "AddGrpC"
 * 	found in "/mnt/EVO/ASN1-C-ITS/DSRC.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#include "PtvRequestType.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_PtvRequestType_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_PtvRequestType_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  3,  3,  0,  4 }	/* (0..4,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_PtvRequestType_value2enum_1[] = {
	{ 0,	10,	"preRequest" },
	{ 1,	11,	"mainRequest" },
	{ 2,	16,	"doorCloseRequest" },
	{ 3,	13,	"cancelRequest" },
	{ 4,	16,	"emergencyRequest" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_PtvRequestType_enum2value_1[] = {
	3,	/* cancelRequest(3) */
	2,	/* doorCloseRequest(2) */
	4,	/* emergencyRequest(4) */
	1,	/* mainRequest(1) */
	0	/* preRequest(0) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_PtvRequestType_specs_1 = {
	asn_MAP_PtvRequestType_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_PtvRequestType_enum2value_1,	/* N => "tag"; sorted by N */
	5,	/* Number of elements in the maps */
	6,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_PtvRequestType_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_PtvRequestType = {
	"PtvRequestType",
	"PtvRequestType",
	&asn_OP_NativeEnumerated,
	asn_DEF_PtvRequestType_tags_1,
	sizeof(asn_DEF_PtvRequestType_tags_1)
		/sizeof(asn_DEF_PtvRequestType_tags_1[0]), /* 1 */
	asn_DEF_PtvRequestType_tags_1,	/* Same as above */
	sizeof(asn_DEF_PtvRequestType_tags_1)
		/sizeof(asn_DEF_PtvRequestType_tags_1[0]), /* 1 */
	{ &asn_OER_type_PtvRequestType_constr_1, &asn_PER_type_PtvRequestType_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_PtvRequestType_specs_1	/* Additional specs */
};

