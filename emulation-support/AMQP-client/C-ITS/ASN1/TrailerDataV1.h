/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "/mnt/EVO/ASN1-stuff/ASN1-C-ITS/CPMv1.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_TrailerDataV1_H_
#define	_TrailerDataV1_H_


#include "asn_application.h"

/* Including external dependencies */
#include "RefPointIdV1.h"
#include "HitchPointOffsetV1.h"
#include "FrontOverhangV1.h"
#include "RearOverhangV1.h"
#include "VehicleWidth.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CartesianAngleV1;

/* TrailerDataV1 */
typedef struct TrailerDataV1 {
	RefPointIdV1_t	 refPointId;
	HitchPointOffsetV1_t	 hitchPointOffset;
	FrontOverhangV1_t	 frontOverhang;
	RearOverhangV1_t	 rearOverhang;
	VehicleWidth_t	*trailerWidth;	/* OPTIONAL */
	struct CartesianAngleV1	*hitchAngle;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TrailerDataV1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TrailerDataV1;
extern asn_SEQUENCE_specifics_t asn_SPC_TrailerDataV1_specs_1;
extern asn_TYPE_member_t asn_MBR_TrailerDataV1_1[6];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CartesianAngleV1.h"

#endif	/* _TrailerDataV1_H_ */
#include "asn_internal.h"
