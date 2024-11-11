/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "/mnt/EVO/ASN1-C-ITS/DSRC.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_RTCMheader_H_
#define	_RTCMheader_H_


#include "asn_application.h"

/* Including external dependencies */
#include "GNSSstatus.h"
#include "AntennaOffsetSet.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* RTCMheader */
typedef struct RTCMheader {
	GNSSstatus_t	 status;
	AntennaOffsetSet_t	 offsetSet;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RTCMheader_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RTCMheader;
extern asn_SEQUENCE_specifics_t asn_SPC_RTCMheader_specs_1;
extern asn_TYPE_member_t asn_MBR_RTCMheader_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _RTCMheader_H_ */
#include "asn_internal.h"
