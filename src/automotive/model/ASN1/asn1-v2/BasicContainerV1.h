/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "CAM-PDU-Descriptions-1.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_BasicContainerV1_H_
#define	_BasicContainerV1_H_


#include "asn_application.h"

/* Including external dependencies */
#include "StationTypeV1.h"
#include "ReferencePositionV1.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* BasicContainerV1 */
typedef struct BasicContainerV1 {
	StationTypeV1_t	 stationType;
	ReferencePositionV1_t	 referencePosition;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} BasicContainerV1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BasicContainerV1;
extern asn_SEQUENCE_specifics_t asn_SPC_BasicContainerV1_specs_1;
extern asn_TYPE_member_t asn_MBR_BasicContainerV1_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _BasicContainerV1_H_ */
#include "asn_internal.h"