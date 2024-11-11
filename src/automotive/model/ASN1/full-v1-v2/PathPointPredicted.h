/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "ETSI-ITS-CDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_PathPointPredicted_H_
#define	_PathPointPredicted_H_


#include "asn_application.h"

/* Including external dependencies */
#include "DeltaLatitude.h"
#include "DeltaLongitude.h"
#include "DeltaAltitude.h"
#include "AltitudeConfidence.h"
#include "DeltaTimeTenthOfSecond.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct PosConfidenceEllipse;

/* PathPointPredicted */
typedef struct PathPointPredicted {
	DeltaLatitude_t	 deltaLatitude;
	DeltaLongitude_t	 deltaLongitude;
	struct PosConfidenceEllipse	*horizontalPositionConfidence;	/* OPTIONAL */
	DeltaAltitude_t	*deltaAltitude;	/* DEFAULT 12800 */
	AltitudeConfidence_t	*altitudeConfidence;	/* DEFAULT 15 */
	DeltaTimeTenthOfSecond_t	 pathDeltaTime;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PathPointPredicted_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PathPointPredicted;
extern asn_SEQUENCE_specifics_t asn_SPC_PathPointPredicted_specs_1;
extern asn_TYPE_member_t asn_MBR_PathPointPredicted_1[6];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "PosConfidenceEllipse.h"

#endif	/* _PathPointPredicted_H_ */
#include "asn_internal.h"
