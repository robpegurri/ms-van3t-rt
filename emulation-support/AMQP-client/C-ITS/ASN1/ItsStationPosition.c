/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "AddGrpC"
 * 	found in "/mnt/EVO/ASN1-C-ITS/DSRC.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#include "ItsStationPosition.h"

asn_TYPE_member_t asn_MBR_ItsStationPosition_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ItsStationPosition, stationID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_StationID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"stationID"
		},
	{ ATF_POINTER, 3, offsetof(struct ItsStationPosition, laneID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LaneID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"laneID"
		},
	{ ATF_POINTER, 2, offsetof(struct ItsStationPosition, nodeXY),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NodeOffsetPointXY,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nodeXY"
		},
	{ ATF_POINTER, 1, offsetof(struct ItsStationPosition, timeReference),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TimeReference,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"timeReference"
		},
};
static const int asn_MAP_ItsStationPosition_oms_1[] = { 1, 2, 3 };
static const ber_tlv_tag_t asn_DEF_ItsStationPosition_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ItsStationPosition_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* stationID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* laneID */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* nodeXY */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* timeReference */
};
asn_SEQUENCE_specifics_t asn_SPC_ItsStationPosition_specs_1 = {
	sizeof(struct ItsStationPosition),
	offsetof(struct ItsStationPosition, _asn_ctx),
	asn_MAP_ItsStationPosition_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_ItsStationPosition_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	4,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_ItsStationPosition = {
	"ItsStationPosition",
	"ItsStationPosition",
	&asn_OP_SEQUENCE,
	asn_DEF_ItsStationPosition_tags_1,
	sizeof(asn_DEF_ItsStationPosition_tags_1)
		/sizeof(asn_DEF_ItsStationPosition_tags_1[0]), /* 1 */
	asn_DEF_ItsStationPosition_tags_1,	/* Same as above */
	sizeof(asn_DEF_ItsStationPosition_tags_1)
		/sizeof(asn_DEF_ItsStationPosition_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_ItsStationPosition_1,
	4,	/* Elements count */
	&asn_SPC_ItsStationPosition_specs_1	/* Additional specs */
};

