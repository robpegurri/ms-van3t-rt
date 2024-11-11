/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "ITS-Container.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_H_
#define	_HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1 {
	HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_unavailable	= 0,
	HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_shedLoad	= 1,
	HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_partsOfVehicles	= 2,
	HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_partsOfTyres	= 3,
	HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_bigObjects	= 4,
	HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_fallenTrees	= 5,
	HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_hubCaps	= 6,
	HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_waitingVehicles	= 7
} e_HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1;

/* HazardousLocation-ObstacleOnTheRoadSubCauseCodeV1 */
typedef long	 HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1;
asn_struct_free_f HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_free;
asn_struct_print_f HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_print;
asn_constr_check_f HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_constraint;
ber_type_decoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_decode_ber;
der_type_encoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_encode_der;
xer_type_decoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_decode_xer;
xer_type_encoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_encode_xer;
oer_type_decoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_decode_oer;
oer_type_encoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_encode_oer;
per_type_decoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_decode_uper;
per_type_encoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _HazardousLocation_ObstacleOnTheRoadSubCauseCodeV1_H_ */
#include "asn_internal.h"
