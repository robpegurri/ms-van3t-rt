/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/mnt/EVO/ASN1-C-ITS/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#include "TimestampItsV1.h"

int
TimestampItsV1_constraint(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const INTEGER_t *st = (const INTEGER_t *)sptr;
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(asn_INTEGER2long(st, &value)) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value too large (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if((value >= 0 && value <= 4398046511103)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

/*
 * This type is implemented using INTEGER,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_TimestampItsV1_constr_1 CC_NOTUSED = {
	{ 8, 1 }	/* (0..4398046511103) */,
	-1};
asn_per_constraints_t asn_PER_type_TimestampItsV1_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 42, -1,  0,  4398046511103 }	/* (0..4398046511103) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const ber_tlv_tag_t asn_DEF_TimestampItsV1_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (2 << 2))
};
asn_TYPE_descriptor_t asn_DEF_TimestampItsV1 = {
	"TimestampItsV1",
	"TimestampItsV1",
	&asn_OP_INTEGER,
	asn_DEF_TimestampItsV1_tags_1,
	sizeof(asn_DEF_TimestampItsV1_tags_1)
		/sizeof(asn_DEF_TimestampItsV1_tags_1[0]), /* 1 */
	asn_DEF_TimestampItsV1_tags_1,	/* Same as above */
	sizeof(asn_DEF_TimestampItsV1_tags_1)
		/sizeof(asn_DEF_TimestampItsV1_tags_1[0]), /* 1 */
	{ &asn_OER_type_TimestampItsV1_constr_1, &asn_PER_type_TimestampItsV1_constr_1, TimestampItsV1_constraint },
	0, 0,	/* Defined elsewhere */
	0	/* No specifics */
};

