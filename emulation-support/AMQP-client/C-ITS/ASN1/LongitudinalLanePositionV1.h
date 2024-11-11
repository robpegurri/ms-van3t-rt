/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "/mnt/EVO/ASN1-stuff/ASN1-C-ITS/CPMv1.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_LongitudinalLanePositionV1_H_
#define	_LongitudinalLanePositionV1_H_


#include "asn_application.h"

/* Including external dependencies */
#include "LongitudinalLanePositionValueV1.h"
#include "LongitudinalLanePositionConfidenceV1.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* LongitudinalLanePositionV1 */
typedef struct LongitudinalLanePositionV1 {
	LongitudinalLanePositionValueV1_t	 longitudinalLanePositionValue;
	LongitudinalLanePositionConfidenceV1_t	 longitudinalLanePositionConfidence;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} LongitudinalLanePositionV1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LongitudinalLanePositionV1;

#ifdef __cplusplus
}
#endif

#endif	/* _LongitudinalLanePositionV1_H_ */
#include "asn_internal.h"
