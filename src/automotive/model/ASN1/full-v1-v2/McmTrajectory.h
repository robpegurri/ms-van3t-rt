/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "MCM-base.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_McmTrajectory_H_
#define	_McmTrajectory_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "Trajectory.h"
#include "CooperationCost.h"
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct McmCategory;

/* McmTrajectory */
typedef struct McmTrajectory {
	long	 trajectoryID;
	Trajectory_t	 trajectory;
	struct McmTrajectory__categories {
		A_SEQUENCE_OF(struct McmCategory) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *categories;
	CooperationCost_t	 cost;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} McmTrajectory_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_McmTrajectory;
extern asn_SEQUENCE_specifics_t asn_SPC_McmTrajectory_specs_1;
extern asn_TYPE_member_t asn_MBR_McmTrajectory_1[4];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "McmCategory.h"

#endif	/* _McmTrajectory_H_ */
#include "asn_internal.h"
