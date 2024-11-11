/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "/mnt/EVO/ASN1-stuff/ASN1-C-ITS/CPMv1.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_FreeSpaceAreaV1_H_
#define	_FreeSpaceAreaV1_H_


#include "asn_application.h"

/* Including external dependencies */
#include "AreaPolygonV1.h"
#include "AreaCircularV1.h"
#include "AreaEllipseV1.h"
#include "AreaRectangleV1.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum FreeSpaceAreaV1_PR {
	FreeSpaceAreaV1_PR_NOTHING,	/* No components present */
	FreeSpaceAreaV1_PR_freeSpacePolygon,
	FreeSpaceAreaV1_PR_freeSpaceCircular,
	FreeSpaceAreaV1_PR_freeSpaceEllipse,
	FreeSpaceAreaV1_PR_freeSpaceRectangle
	/* Extensions may appear below */
	
} FreeSpaceAreaV1_PR;

/* FreeSpaceAreaV1 */
typedef struct FreeSpaceAreaV1 {
	FreeSpaceAreaV1_PR present;
	union FreeSpaceAreaV1_u {
		AreaPolygonV1_t	 freeSpacePolygon;
		AreaCircularV1_t	 freeSpaceCircular;
		AreaEllipseV1_t	 freeSpaceEllipse;
		AreaRectangleV1_t	 freeSpaceRectangle;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FreeSpaceAreaV1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FreeSpaceAreaV1;
extern asn_CHOICE_specifics_t asn_SPC_FreeSpaceAreaV1_specs_1;
extern asn_TYPE_member_t asn_MBR_FreeSpaceAreaV1_1[4];
extern asn_per_constraints_t asn_PER_type_FreeSpaceAreaV1_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _FreeSpaceAreaV1_H_ */
#include "asn_internal.h"
