/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "CAM-PDU-Descriptions-1.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "LowFrequencyContainerV1.h"

static asn_oer_constraints_t asn_OER_type_LowFrequencyContainerV1_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_LowFrequencyContainerV1_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_LowFrequencyContainerV1_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LowFrequencyContainerV1, choice.basicVehicleContainerLowFrequency),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BasicVehicleContainerLowFrequencyV1,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"basicVehicleContainerLowFrequency"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_LowFrequencyContainerV1_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* basicVehicleContainerLowFrequency */
};
asn_CHOICE_specifics_t asn_SPC_LowFrequencyContainerV1_specs_1 = {
	sizeof(struct LowFrequencyContainerV1),
	offsetof(struct LowFrequencyContainerV1, _asn_ctx),
	offsetof(struct LowFrequencyContainerV1, present),
	sizeof(((struct LowFrequencyContainerV1 *)0)->present),
	asn_MAP_LowFrequencyContainerV1_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0,
	1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_LowFrequencyContainerV1 = {
	"LowFrequencyContainerV1",
	"LowFrequencyContainerV1",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ &asn_OER_type_LowFrequencyContainerV1_constr_1, &asn_PER_type_LowFrequencyContainerV1_constr_1, CHOICE_constraint },
	asn_MBR_LowFrequencyContainerV1_1,
	1,	/* Elements count */
	&asn_SPC_LowFrequencyContainerV1_specs_1	/* Additional specs */
};

