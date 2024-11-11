/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "/mnt/EVO/ASN1-C-ITS/ISO14906(2018)EfcDsrcApplicationv6-patched.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_VehicleWeightLimits_H_
#define	_VehicleWeightLimits_H_


#include "asn_application.h"

/* Including external dependencies */
#include "Int2.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* VehicleWeightLimits */
typedef struct VehicleWeightLimits {
	Int2_t	 vehicleMaxLadenWeight;
	Int2_t	 vehicleTrainMaximumWeight;
	Int2_t	 vehicleWeightUnladen;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} VehicleWeightLimits_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_VehicleWeightLimits;
extern asn_SEQUENCE_specifics_t asn_SPC_VehicleWeightLimits_specs_1;
extern asn_TYPE_member_t asn_MBR_VehicleWeightLimits_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _VehicleWeightLimits_H_ */
#include "asn_internal.h"