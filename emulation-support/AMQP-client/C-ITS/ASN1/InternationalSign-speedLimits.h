/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "GDD"
 * 	found in "/mnt/EVO/ASN1-C-ITS/GDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_InternationalSign_speedLimits_H_
#define	_InternationalSign_speedLimits_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "Code-Units.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* InternationalSign-speedLimits */
typedef struct InternationalSign_speedLimits {
	long	*speedLimitMax	/* OPTIONAL */;
	long	*speedLimitMin	/* OPTIONAL */;
	Code_Units_t	 unit;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} InternationalSign_speedLimits_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_InternationalSign_speedLimits;
extern asn_SEQUENCE_specifics_t asn_SPC_InternationalSign_speedLimits_specs_1;
extern asn_TYPE_member_t asn_MBR_InternationalSign_speedLimits_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _InternationalSign_speedLimits_H_ */
#include "asn_internal.h"
