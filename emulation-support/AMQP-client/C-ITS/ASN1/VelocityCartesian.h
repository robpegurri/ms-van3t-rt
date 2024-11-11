/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "/mnt/EVO/asn1c-forks/output/CPM-all.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_VelocityCartesian_H_
#define	_VelocityCartesian_H_


#include "asn_application.h"

/* Including external dependencies */
#include "VelocityComponent.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct VelocityComponent;

/* VelocityCartesian */
typedef struct VelocityCartesian {
	VelocityComponent_t	 xVelocity;
	VelocityComponent_t	 yVelocity;
	struct VelocityComponent	*zVelocity;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} VelocityCartesian_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_VelocityCartesian;
extern asn_SEQUENCE_specifics_t asn_SPC_VelocityCartesian_specs_1;
extern asn_TYPE_member_t asn_MBR_VelocityCartesian_1[3];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "VelocityComponent.h"

#endif	/* _VelocityCartesian_H_ */
#include "asn_internal.h"
