/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "ITS-Container.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "SpeedV1.h"

asn_TYPE_member_t asn_MBR_SpeedV1_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct SpeedV1, speedValue),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SpeedValueV1,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"speedValue"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SpeedV1, speedConfidence),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SpeedConfidenceV1,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"speedConfidence"
		},
};
static const ber_tlv_tag_t asn_DEF_SpeedV1_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_SpeedV1_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* speedValue */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* speedConfidence */
};
asn_SEQUENCE_specifics_t asn_SPC_SpeedV1_specs_1 = {
	sizeof(struct SpeedV1),
	offsetof(struct SpeedV1, _asn_ctx),
	asn_MAP_SpeedV1_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_SpeedV1 = {
	"SpeedV1",
	"SpeedV1",
	&asn_OP_SEQUENCE,
	asn_DEF_SpeedV1_tags_1,
	sizeof(asn_DEF_SpeedV1_tags_1)
		/sizeof(asn_DEF_SpeedV1_tags_1[0]), /* 1 */
	asn_DEF_SpeedV1_tags_1,	/* Same as above */
	sizeof(asn_DEF_SpeedV1_tags_1)
		/sizeof(asn_DEF_SpeedV1_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_SpeedV1_1,
	2,	/* Elements count */
	&asn_SPC_SpeedV1_specs_1	/* Additional specs */
};

