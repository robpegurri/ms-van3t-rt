/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "/mnt/EVO/ASN1-stuff/ASN1-C-ITS/CPMv1.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_AreaRectangleV1_H_
#define	_AreaRectangleV1_H_


#include "asn_application.h"

/* Including external dependencies */
#include "SemiRangeLengthV1.h"
#include "WGS84AngleValueV1.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct OffsetPointV1;

/* AreaRectangleV1 */
typedef struct AreaRectangleV1 {
	struct OffsetPointV1	*nodeCenterPoint;	/* OPTIONAL */
	SemiRangeLengthV1_t	 semiMajorRangeLength;
	SemiRangeLengthV1_t	 semiMinorRangeLength;
	WGS84AngleValueV1_t	 semiMajorRangeOrientation;
	SemiRangeLengthV1_t	*semiHeight;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AreaRectangleV1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AreaRectangleV1;
extern asn_SEQUENCE_specifics_t asn_SPC_AreaRectangleV1_specs_1;
extern asn_TYPE_member_t asn_MBR_AreaRectangleV1_1[5];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "OffsetPointV1.h"

#endif	/* _AreaRectangleV1_H_ */
#include "asn_internal.h"
