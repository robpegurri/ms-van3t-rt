/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "/mnt/EVO/ASN1-stuff/ASN1-C-ITS/CPMv1.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#include "AreaRadialV1.h"

asn_TYPE_member_t asn_MBR_AreaRadialV1_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct AreaRadialV1, range),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RangeV1,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"range"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct AreaRadialV1, stationaryHorizontalOpeningAngleStart),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_WGS84AngleValueV1,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"stationaryHorizontalOpeningAngleStart"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct AreaRadialV1, stationaryHorizontalOpeningAngleEnd),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_WGS84AngleValueV1,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"stationaryHorizontalOpeningAngleEnd"
		},
	{ ATF_POINTER, 4, offsetof(struct AreaRadialV1, verticalOpeningAngleStart),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CartesianAngleValueV1,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"verticalOpeningAngleStart"
		},
	{ ATF_POINTER, 3, offsetof(struct AreaRadialV1, verticalOpeningAngleEnd),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CartesianAngleValueV1,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"verticalOpeningAngleEnd"
		},
	{ ATF_POINTER, 2, offsetof(struct AreaRadialV1, sensorPositionOffset),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OffsetPointV1,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"sensorPositionOffset"
		},
	{ ATF_POINTER, 1, offsetof(struct AreaRadialV1, sensorHeight),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SensorHeightV1,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"sensorHeight"
		},
};
static const int asn_MAP_AreaRadialV1_oms_1[] = { 3, 4, 5, 6 };
static const ber_tlv_tag_t asn_DEF_AreaRadialV1_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_AreaRadialV1_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* range */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* stationaryHorizontalOpeningAngleStart */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* stationaryHorizontalOpeningAngleEnd */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* verticalOpeningAngleStart */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* verticalOpeningAngleEnd */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* sensorPositionOffset */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 } /* sensorHeight */
};
asn_SEQUENCE_specifics_t asn_SPC_AreaRadialV1_specs_1 = {
	sizeof(struct AreaRadialV1),
	offsetof(struct AreaRadialV1, _asn_ctx),
	asn_MAP_AreaRadialV1_tag2el_1,
	7,	/* Count of tags in the map */
	asn_MAP_AreaRadialV1_oms_1,	/* Optional members */
	4, 0,	/* Root/Additions */
	7,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_AreaRadialV1 = {
	"AreaRadialV1",
	"AreaRadialV1",
	&asn_OP_SEQUENCE,
	asn_DEF_AreaRadialV1_tags_1,
	sizeof(asn_DEF_AreaRadialV1_tags_1)
		/sizeof(asn_DEF_AreaRadialV1_tags_1[0]), /* 1 */
	asn_DEF_AreaRadialV1_tags_1,	/* Same as above */
	sizeof(asn_DEF_AreaRadialV1_tags_1)
		/sizeof(asn_DEF_AreaRadialV1_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_AreaRadialV1_1,
	7,	/* Elements count */
	&asn_SPC_AreaRadialV1_specs_1	/* Additional specs */
};

