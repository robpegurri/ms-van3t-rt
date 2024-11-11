/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CITSapplMgmtIDs"
 * 	found in asn1/ISO17419.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_Ext2_H_
#define	_Ext2_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "Ext3.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Ext2_PR {
	Ext2_PR_NOTHING,	/* No components present */
	Ext2_PR_content,
	Ext2_PR_extension
} Ext2_PR;

/* Ext2 */
typedef struct Ext2 {
	Ext2_PR present;
	union Ext2_u {
		long	 content;
		Ext3_t	 extension;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Ext2_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Ext2;
extern asn_CHOICE_specifics_t asn_SPC_Ext2_specs_1;
extern asn_TYPE_member_t asn_MBR_Ext2_1[2];
extern asn_per_constraints_t asn_PER_type_Ext2_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _Ext2_H_ */
#include "asn_internal.h"
