/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "/mnt/EVO/asn1c-forks/output/CPM-all.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_CenDsrcTollingZone_H_
#define	_CenDsrcTollingZone_H_


#include "asn_application.h"

/* Including external dependencies */
#include "Latitude.h"
#include "Longitude.h"
#include "ProtectedZoneId.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CenDsrcTollingZone */
typedef struct CenDsrcTollingZone {
	Latitude_t	 protectedZoneLatitude;
	Longitude_t	 protectedZoneLongitude;
	ProtectedZoneId_t	*cenDsrcTollingZoneId;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CenDsrcTollingZone_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CenDsrcTollingZone;

#ifdef __cplusplus
}
#endif

#endif	/* _CenDsrcTollingZone_H_ */
#include "asn_internal.h"
