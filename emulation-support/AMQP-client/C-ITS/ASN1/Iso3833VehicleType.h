/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "/mnt/EVO/asn1c-forks/output/CPM-all.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_Iso3833VehicleType_H_
#define	_Iso3833VehicleType_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Iso3833VehicleType {
	Iso3833VehicleType_passengerCar	= 0,
	Iso3833VehicleType_saloon	= 1,
	Iso3833VehicleType_convertibleSaloon	= 2,
	Iso3833VehicleType_pullmanSaloon	= 3,
	Iso3833VehicleType_stationWagon	= 4,
	Iso3833VehicleType_truckStationWagon	= 5,
	Iso3833VehicleType_coupe	= 6,
	Iso3833VehicleType_convertible	= 7,
	Iso3833VehicleType_multipurposePassengerCar	= 8,
	Iso3833VehicleType_forwardControlPassengerCar	= 9,
	Iso3833VehicleType_specialPassengerCar	= 10,
	Iso3833VehicleType_bus	= 11,
	Iso3833VehicleType_minibus	= 12,
	Iso3833VehicleType_urbanBus	= 13,
	Iso3833VehicleType_interurbanCoach	= 14,
	Iso3833VehicleType_longDistanceCoach	= 15,
	Iso3833VehicleType_articulatedBus	= 16,
	Iso3833VehicleType_trolleyBus	= 17,
	Iso3833VehicleType_specialBus	= 18,
	Iso3833VehicleType_commercialVehicle	= 19,
	Iso3833VehicleType_specialCommercialVehicle	= 20,
	Iso3833VehicleType_specialVehicle	= 21,
	Iso3833VehicleType_trailingTowingVehicle	= 22,
	Iso3833VehicleType_semiTrailerTowingVehicle	= 23,
	Iso3833VehicleType_trailer	= 24,
	Iso3833VehicleType_busTrailer	= 25,
	Iso3833VehicleType_generalPurposeTrailer	= 26,
	Iso3833VehicleType_caravan	= 27,
	Iso3833VehicleType_specialTrailer	= 28,
	Iso3833VehicleType_semiTrailer	= 29,
	Iso3833VehicleType_busSemiTrailer	= 30,
	Iso3833VehicleType_generalPurposeSemiTrailer	= 31,
	Iso3833VehicleType_specialSemiTrailer	= 32,
	Iso3833VehicleType_roadTrain	= 33,
	Iso3833VehicleType_passengerRoadTrain	= 34,
	Iso3833VehicleType_articulatedRoadTrain	= 35,
	Iso3833VehicleType_doubleRoadTrain	= 36,
	Iso3833VehicleType_compositeRoadTrain	= 37,
	Iso3833VehicleType_specialRoadTrain	= 38,
	Iso3833VehicleType_moped	= 39,
	Iso3833VehicleType_motorCycle	= 40
} e_Iso3833VehicleType;

/* Iso3833VehicleType */
typedef long	 Iso3833VehicleType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Iso3833VehicleType;
asn_struct_free_f Iso3833VehicleType_free;
asn_struct_print_f Iso3833VehicleType_print;
asn_constr_check_f Iso3833VehicleType_constraint;
ber_type_decoder_f Iso3833VehicleType_decode_ber;
der_type_encoder_f Iso3833VehicleType_encode_der;
xer_type_decoder_f Iso3833VehicleType_decode_xer;
xer_type_encoder_f Iso3833VehicleType_encode_xer;
jer_type_encoder_f Iso3833VehicleType_encode_jer;
oer_type_decoder_f Iso3833VehicleType_decode_oer;
oer_type_encoder_f Iso3833VehicleType_encode_oer;
per_type_decoder_f Iso3833VehicleType_decode_uper;
per_type_encoder_f Iso3833VehicleType_encode_uper;
per_type_decoder_f Iso3833VehicleType_decode_aper;
per_type_encoder_f Iso3833VehicleType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _Iso3833VehicleType_H_ */
#include "asn_internal.h"
