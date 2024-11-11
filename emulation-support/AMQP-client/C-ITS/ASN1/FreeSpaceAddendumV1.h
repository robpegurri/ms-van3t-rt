/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "/mnt/EVO/ASN1-stuff/ASN1-C-ITS/CPMv1.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_FreeSpaceAddendumV1_H_
#define	_FreeSpaceAddendumV1_H_


#include "asn_application.h"

/* Including external dependencies */
#include "FreeSpaceConfidenceV1.h"
#include "FreeSpaceAreaV1.h"
#include "ShadowingAppliesV1.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct SensorIdListV1;

/* FreeSpaceAddendumV1 */
typedef struct FreeSpaceAddendumV1 {
	FreeSpaceConfidenceV1_t	 freeSpaceConfidence;
	FreeSpaceAreaV1_t	 freeSpaceArea;
	struct SensorIdListV1	*sensorIDList;	/* OPTIONAL */
	ShadowingAppliesV1_t	*shadowingApplies;	/* DEFAULT TRUE */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FreeSpaceAddendumV1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FreeSpaceAddendumV1;
extern asn_SEQUENCE_specifics_t asn_SPC_FreeSpaceAddendumV1_specs_1;
extern asn_TYPE_member_t asn_MBR_FreeSpaceAddendumV1_1[4];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "SensorIdListV1.h"

#endif	/* _FreeSpaceAddendumV1_H_ */
#include "asn_internal.h"
