/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/mnt/EVO/ASN1-C-ITS/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_ProtectedCommunicationZonesRSUV1_H_
#define	_ProtectedCommunicationZonesRSUV1_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtectedCommunicationZoneV1;

/* ProtectedCommunicationZonesRSUV1 */
typedef struct ProtectedCommunicationZonesRSUV1 {
	A_SEQUENCE_OF(struct ProtectedCommunicationZoneV1) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtectedCommunicationZonesRSUV1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ProtectedCommunicationZonesRSUV1;
extern asn_SET_OF_specifics_t asn_SPC_ProtectedCommunicationZonesRSUV1_specs_1;
extern asn_TYPE_member_t asn_MBR_ProtectedCommunicationZonesRSUV1_1[1];
extern asn_per_constraints_t asn_PER_type_ProtectedCommunicationZonesRSUV1_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtectedCommunicationZoneV1.h"

#endif	/* _ProtectedCommunicationZonesRSUV1_H_ */
#include "asn_internal.h"
