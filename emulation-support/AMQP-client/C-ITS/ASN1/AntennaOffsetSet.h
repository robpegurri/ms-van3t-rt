/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "/mnt/EVO/ASN1-C-ITS/DSRC.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_AntennaOffsetSet_H_
#define	_AntennaOffsetSet_H_


#include "asn_application.h"

/* Including external dependencies */
#include "Offset-B12.h"
#include "Offset-B09.h"
#include "Offset-B10.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* AntennaOffsetSet */
typedef struct AntennaOffsetSet {
	Offset_B12_t	 antOffsetX;
	Offset_B09_t	 antOffsetY;
	Offset_B10_t	 antOffsetZ;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AntennaOffsetSet_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AntennaOffsetSet;
extern asn_SEQUENCE_specifics_t asn_SPC_AntennaOffsetSet_specs_1;
extern asn_TYPE_member_t asn_MBR_AntennaOffsetSet_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _AntennaOffsetSet_H_ */
#include "asn_internal.h"
