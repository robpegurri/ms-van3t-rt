/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "ETSI-ITS-CDD.asn"
 */

#ifndef	_CircularShape_H_
#define	_CircularShape_H_


#include "asn_application.h"

/* Including external dependencies */
#include "StandardLength12b.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CartesianPosition3d;

/* CircularShape */
typedef struct CircularShape {
	struct CartesianPosition3d	*shapeReferencePoint	/* OPTIONAL */;
	StandardLength12b_t	 radius;
	StandardLength12b_t	*height	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CircularShape_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CircularShape;
extern asn_SEQUENCE_specifics_t asn_SPC_CircularShape_specs_1;
extern asn_TYPE_member_t asn_MBR_CircularShape_1[3];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CartesianPosition3d.h"

#endif	/* _CircularShape_H_ */
#include "asn_internal.h"
