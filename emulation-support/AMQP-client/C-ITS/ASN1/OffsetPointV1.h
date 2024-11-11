/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "/mnt/EVO/ASN1-stuff/ASN1-C-ITS/CPMv1.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_OffsetPointV1_H_
#define	_OffsetPointV1_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NodeOffsetPointXY.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NodeOffsetPointZV1;

/* OffsetPointV1 */
typedef struct OffsetPointV1 {
	NodeOffsetPointXY_t	 nodeOffsetPointxy;
	struct NodeOffsetPointZV1	*nodeOffsetPointZ;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} OffsetPointV1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_OffsetPointV1;
extern asn_SEQUENCE_specifics_t asn_SPC_OffsetPointV1_specs_1;
extern asn_TYPE_member_t asn_MBR_OffsetPointV1_1[2];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "NodeOffsetPointZV1.h"

#endif	/* _OffsetPointV1_H_ */
#include "asn_internal.h"
