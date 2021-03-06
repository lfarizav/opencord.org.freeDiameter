/*
* Copyright (c) 2017 Sprint
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/****************
 Generated By: fdtool enhancements to diafuzzer
 License: same as freeDiameter
****************/


/* 
 * Dictionary definitions of objects specified in CreditControl (rfc4006bis).
 */
#include <freeDiameter/extension.h>

#define PROTO_VER "rfc4006bis"
#define GEN_DATE  1506697121.72

const char *creditcontrol_proto_ver = PROTO_VER;
const double creditcontrol_gen_date = GEN_DATE;

/* The content of this file follows the same structure as dict_base_proto.c */

#define CHECK_dict_new( _type, _data, _parent, _ref )                                     \
{                                                                                         \
    int _ret = fd_dict_new( fd_g_config->cnf_dict, (_type), (_data), (_parent), (_ref) ); \
    if ( _ret != 0 && _ret != EEXIST )                                                    \
       return _ret;                                                                       \
}

#define CHECK_dict_search( _type, _criteria, _what, _result )		\
    CHECK_FCT(  fd_dict_search( fd_g_config->cnf_dict, (_type), (_criteria), (_what), (_result), ENOENT) );

struct local_rules_definition {
    struct dict_avp_request avp_vendor_plus_name;
    enum rule_position	position;
    int 			min;
    int			max;
};

#define RULE_ORDER( _position ) ((((_position) == RULE_FIXED_HEAD) || ((_position) == RULE_FIXED_TAIL)) ? 1 : 0 )

/* Attention! This version of the macro uses AVP_BY_NAME_AND_VENDOR, in contrast to most other copies! */
#define PARSE_loc_rules( _rulearray, _parent) {                                                         \
        int __ar;                                                                                       \
        for (__ar=0; __ar < sizeof(_rulearray) / sizeof((_rulearray)[0]); __ar++) {                     \
                struct dict_rule_data __data = { NULL,                                                  \
                        (_rulearray)[__ar].position,                                                    \
                        0,                                                                              \
                        (_rulearray)[__ar].min,                                                         \
                        (_rulearray)[__ar].max};                                                        \
                __data.rule_order = RULE_ORDER(__data.rule_position);                                   \
                CHECK_FCT(  fd_dict_search(                                                             \
                        fd_g_config->cnf_dict,                                                          \
                        DICT_AVP,                                                                       \
                        AVP_BY_NAME_AND_VENDOR,                                                         \
                        &(_rulearray)[__ar].avp_vendor_plus_name,                                       \
                        &__data.rule_avp, 0 ) );                                                        \
                if ( !__data.rule_avp ) {                                                               \
                        TRACE_DEBUG(INFO, "AVP Not found: '%s'", (_rulearray)[__ar].avp_vendor_plus_name.avp_name);             \
                        return ENOENT;                                                                  \
                }                                                                                       \
                {                                                                                       \
                         int _ret = fd_dict_new( fd_g_config->cnf_dict, DICT_RULE, &(__data), (_parent), NULL ); \
                         if ( _ret != 0 && _ret != EEXIST )      {                                      \
                                TRACE_DEBUG(INFO, "Error on rule with AVP '%s'",                        \
                                            (_rulearray)[__ar].avp_vendor_plus_name.avp_name);          \
                                return EINVAL;                                                          \
                         }                                                                              \
                }                                                                                       \
        }                                                                                               \
}

#define CHECK_vendor_new( _data ) { \
        struct dict_object * vendor_found; \
        if (fd_dict_search(fd_g_config->cnf_dict,DICT_VENDOR,VENDOR_BY_ID,&_data.vendor_id,&vendor_found,ENOENT) == ENOENT) { \
                CHECK_FCT(fd_dict_new(fd_g_config->cnf_dict, DICT_VENDOR, &_data, NULL, NULL)); \
        } \
}

#define enumval_def_u32( _val_, _str_ )		\
    { _str_, 		{ .u32 = _val_ }}

#define enumval_def_os( _len_, _val_, _str_ )				\
    { _str_, 		{ .os = { .data = (unsigned char *)_val_, .len = _len_ }}}


static int dict_creditcontrol_load_defs(char * conffile)
{
   TRACE_ENTRY("%p", conffile);
	struct dict_object * app_id4;

	/* Application Section */
	{
	  {
			struct dict_application_data data = { 4, "CreditControl" };
			CHECK_dict_new( DICT_APPLICATION, &data, NULL, &app_id4)
	  }
	  /* Result codes */
	  {
			struct dict_object *type;
			CHECK_dict_search(DICT_TYPE, TYPE_BY_NAME, "Enumerated(Result-Code)",&type);
			struct dict_enumval_data        t_1 = { "is", { .u32=10 }};
			struct dict_enumval_data        t_2 = { "Services", { .u32=3 }};
			struct dict_enumval_data        t_3 = { "KS", { .u32=66251 }};

			CHECK_dict_new( DICT_ENUMVAL, &t_1, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_2, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_3, type, NULL);

	  }
	}


   /* AVP section */
   {
		struct dict_object * Address_type;
		struct dict_object * UTF8String_type;
		struct dict_object * DiameterIdentity_type;
		struct dict_object * DiameterURI_type;
		struct dict_object * Time_type;
		struct dict_object * IPFilterRule_type;

		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "Address", &Address_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "UTF8String", &UTF8String_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "DiameterIdentity", &DiameterIdentity_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "DiameterURI", &DiameterURI_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "Time", &Time_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "IPFilterRule", &IPFilterRule_type);

	
   }

   /* Commands section */
   {
		/* Credit-Control-Request */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				272,	/* Code */
				"Credit-Control-Request",	/* Name */
				CMD_FLAG_REQUEST | CMD_FLAG_ERROR,	/* Fixed flags */
				CMD_FLAG_REQUEST | CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id4, &cmd)
		}
		/* Credit-Control-Answer */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				272,	/* Code */
				"Credit-Control-Answer",	/* Name */
				CMD_FLAG_REQUEST,	/* Fixed flags */
				CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id4, &cmd)
		}

   }

   return 0;
}

static int dict_creditcontrol_load_rules(char * conffile)
{
   /* Grouped AVP section */
   {

   }	

   /* Commands section */
   {
	  /* Credit-Control-Request */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Credit-Control-Request", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Application-Id"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Service-Context-Id"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "CC-Request-Type"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "CC-Request-Number"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Host"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Name"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "CC-Sub-Session-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Acct-Multi-Session-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-State-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Event-Timestamp"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Subscription-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Subscription-Id-Extension"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Service-Identifier"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Termination-Cause"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Requested-Service-Unit"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Requested-Action"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Used-Service-Unit"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Multiple-Services-Indicator"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Multiple-Services-Credit-Control"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Service-Parameter-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "CC-Correlation-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Equipment-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Equipment-Info-Extension"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Proxy-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Route-Record"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Credit-Control-Answer */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Credit-Control-Answer", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Result-Code"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Application-Id"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "CC-Request-Type"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "CC-Request-Number"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Name"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "CC-Session-Failover"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "CC-Sub-Session-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Acct-Multi-Session-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-State-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Event-Timestamp"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Granted-Service-Unit"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Multiple-Services-Credit-Control"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Cost-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Final-Unit-Indication"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "QoS-Final-Unit-Indication"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Check-Balance-Result"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Credit-Control-Failure-Handling"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Direct-Debiting-Failure-Handling"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Validity-Time"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Redirect-Host"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Redirect-Host-Usage"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Redirect-Max-Cache-Time"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Proxy-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Route-Record"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Failed-AVP"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }

   }

   LOG_D( "Extension 'Dictionary definitions for CreditControl (rfc4006bis)' initialized");
   return 0;
}

int dict_entry(char * conffile)
{
	dict_creditcontrol_load_defs(conffile);
	return dict_creditcontrol_load_rules(conffile);
}

const char* dict_creditcontrol_proto_ver(char * conffile) {
	return creditcontrol_proto_ver;
}

const double dict_creditcontrol_gen_ts(char * conffile) {
	return creditcontrol_gen_date;
}

EXTENSION_ENTRY2("dict_creditcontrol", dict_creditcontrol_load_defs, dict_creditcontrol_load_rules, "dict_rfc4006bis_avps", "dict_rfc7155_avps", "dict_rfc5777_avps");



