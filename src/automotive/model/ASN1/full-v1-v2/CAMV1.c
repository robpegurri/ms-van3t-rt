/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "/mnt/EVO/ASN1-C-ITS/CAM-PDU-Descriptions-1.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#include "CAMV1.h"

static asn_TYPE_member_t asn_MBR_CAMV1_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CAMV1, header),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ItsPduHeaderV1,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"header"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CAMV1, cam),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CoopAwarenessV1,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"cam"
		},
};
static const ber_tlv_tag_t asn_DEF_CAMV1_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_CAMV1_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* header */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* cam */
};
static asn_SEQUENCE_specifics_t asn_SPC_CAMV1_specs_1 = {
	sizeof(struct CAMV1),
	offsetof(struct CAMV1, _asn_ctx),
	asn_MAP_CAMV1_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_CAMV1 = {
	"CAMV1",
	"CAMV1",
	&asn_OP_SEQUENCE,
	asn_DEF_CAMV1_tags_1,
	sizeof(asn_DEF_CAMV1_tags_1)
		/sizeof(asn_DEF_CAMV1_tags_1[0]), /* 1 */
	asn_DEF_CAMV1_tags_1,	/* Same as above */
	sizeof(asn_DEF_CAMV1_tags_1)
		/sizeof(asn_DEF_CAMV1_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_CAMV1_1,
	2,	/* Elements count */
	&asn_SPC_CAMV1_specs_1	/* Additional specs */
};
