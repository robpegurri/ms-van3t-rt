/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "ETSI-ITS-CDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_GeneralizedLanePosition_H_
#define	_GeneralizedLanePosition_H_


#include "asn_application.h"

/* Including external dependencies */
#include "LanePosition.h"
#include "LanePositionAndType.h"
#include "TrafficIslandPosition.h"
#include "MapPosition.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum GeneralizedLanePosition_PR {
	GeneralizedLanePosition_PR_NOTHING,	/* No components present */
	GeneralizedLanePosition_PR_trafficLanePosition,
	GeneralizedLanePosition_PR_nonTrafficLanePosition,
	GeneralizedLanePosition_PR_trafficIslandPosition,
	GeneralizedLanePosition_PR_mapPosition
	/* Extensions may appear below */
	
} GeneralizedLanePosition_PR;

/* GeneralizedLanePosition */
typedef struct GeneralizedLanePosition {
	GeneralizedLanePosition_PR present;
	union GeneralizedLanePosition_u {
		LanePosition_t	 trafficLanePosition;
		LanePositionAndType_t	 nonTrafficLanePosition;
		TrafficIslandPosition_t	 trafficIslandPosition;
		MapPosition_t	 mapPosition;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GeneralizedLanePosition_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GeneralizedLanePosition;

#ifdef __cplusplus
}
#endif

#endif	/* _GeneralizedLanePosition_H_ */
#include "asn_internal.h"
