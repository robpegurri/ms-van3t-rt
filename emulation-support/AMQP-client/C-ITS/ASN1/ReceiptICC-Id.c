/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "/mnt/EVO/ASN1-C-ITS/ISO14906(2018)EfcDsrcApplicationv6-patched.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#include "ReceiptICC-Id.h"

/*
 * This type is implemented using ICC_Id,
 * so here we adjust the DEF accordingly.
 */
static const ber_tlv_tag_t asn_DEF_ReceiptICC_Id_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (4 << 2))
};
asn_TYPE_descriptor_t asn_DEF_ReceiptICC_Id = {
	"ReceiptICC-Id",
	"ReceiptICC-Id",
	&asn_OP_OCTET_STRING,
	asn_DEF_ReceiptICC_Id_tags_1,
	sizeof(asn_DEF_ReceiptICC_Id_tags_1)
		/sizeof(asn_DEF_ReceiptICC_Id_tags_1[0]), /* 1 */
	asn_DEF_ReceiptICC_Id_tags_1,	/* Same as above */
	sizeof(asn_DEF_ReceiptICC_Id_tags_1)
		/sizeof(asn_DEF_ReceiptICC_Id_tags_1[0]), /* 1 */
	{ 0, 0, OCTET_STRING_constraint },
	0, 0,	/* No members */
	&asn_SPC_OCTET_STRING_specs	/* Additional specs */
};

