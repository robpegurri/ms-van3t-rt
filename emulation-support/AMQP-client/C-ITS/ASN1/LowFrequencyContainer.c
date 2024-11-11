/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "/mnt/EVO/ASN1-C-ITS/CAM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#include "LowFrequencyContainer.h"

static int
memb_basicVehicleContainerLowFrequency_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		/* Nothing is here. See below */
	}
	
	return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
}

static asn_oer_constraints_t asn_OER_memb_basicVehicleContainerLowFrequency_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_memb_basicVehicleContainerLowFrequency_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_LowFrequencyContainer_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_LowFrequencyContainer_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_LowFrequencyContainer_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LowFrequencyContainer, choice.basicVehicleContainerLowFrequency),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BasicVehicleContainerLowFrequency,
		0,
		{ &asn_OER_memb_basicVehicleContainerLowFrequency_constr_2, &asn_PER_memb_basicVehicleContainerLowFrequency_constr_2,  memb_basicVehicleContainerLowFrequency_constraint_1 },
		0, 0, /* No default value */
		"basicVehicleContainerLowFrequency"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_LowFrequencyContainer_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* basicVehicleContainerLowFrequency */
};
asn_CHOICE_specifics_t asn_SPC_LowFrequencyContainer_specs_1 = {
	sizeof(struct LowFrequencyContainer),
	offsetof(struct LowFrequencyContainer, _asn_ctx),
	offsetof(struct LowFrequencyContainer, present),
	sizeof(((struct LowFrequencyContainer *)0)->present),
	asn_MAP_LowFrequencyContainer_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0,
	1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_LowFrequencyContainer = {
	"LowFrequencyContainer",
	"LowFrequencyContainer",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ &asn_OER_type_LowFrequencyContainer_constr_1, &asn_PER_type_LowFrequencyContainer_constr_1, CHOICE_constraint },
	asn_MBR_LowFrequencyContainer_1,
	1,	/* Elements count */
	&asn_SPC_LowFrequencyContainer_specs_1	/* Additional specs */
};
