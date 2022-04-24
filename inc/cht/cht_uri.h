#ifndef CHT_URI_H
#define CHT_URI_H 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct cht_uri_s cht_uri_t;

/* <-- CHT URI KIND --> */
#define CHT_URI_KIND_ABSOLUTE_OR_REALTIVE   (0)
#define CHT_URI_KIND_ABSOLUTE               (1)
#define CHT_URI_KIND_RELATIVE               (2)
/* <!-- CHT URI KIND --> */

/* <-- CHT URI COMPONENTS FLAG --> */
#define CHT_URI_CFLAG_SCHEME            (0x1)
#define CHT_URI_CFLAG_USER_INFO         (0x2)
#define CHT_URI_CFLAG_HOST              (0x4)
#define CHT_URI_CFLAG_PORT              (0x8)
#define CHT_URI_CFLAG_PATH              (0x10)
#define CHT_URI_CFLAG_QUERY             (0x20)
#define CHT_URI_CFLAG_FRAGMENT          (0x40)
#define CHT_URI_CFLAG_STRONG_PORT       (0x80)
#define CHT_URI_CFLAG_NORMALIZED_HOST   (0x100)
#define CHT_URI_CFLAG_KEEP_DELIMITER    (0x40000000)

#define CHT_URI_CFLAG_ABSOLUTE_URI      \
    (CHT_URI_CFLAG_SCHEME               \
     | CHT_URI_CFLAG_USER_INFO          \
     | CHT_URI_CFLAG_HOST               \
     | CHT_URI_CFLAG_PORT               \
     | CHT_URI_CFLAG_PATH               \
     | CHT_URI_CFLAG_QUERY              \
     | CHT_URI_CFLAG_FRAGMENT)

#define CHT_URI_CFLAG_HOST_AND_PORT     \
    (CHT_URI_CFLAG_HOST                 \
    | CHT_URI_CFLAG_STRONG_PORT)

#define CHT_URI_CFLAG_STRONG_AUTHOTIRY  \
    (CHT_URI_CFLAG_USER_INFO            \
     | CHT_URI_CFLAG_HOST_AND_PORT)

#define CHT_URI_CFLAG_SCHEME_AND_SERVER \
    (CHT_URI_CFLAG_SCHEME               \
     | CHT_URI_CFLAG_HOST               \
     | CHT_URI_CFLAG_PORT)

#define CHT_URI_CFLAG_PATH_AND_QUERY    \
    (CHT_URI_CLFAG_PATH                 \
     | CHT_URI_CFLAG_QUERY)

#define CHT_URI_CFLAG_HTTP_REQUEST_URL  \
    (CHT_URI_CFLAG_SCHEME_AND_SERVER    \
     | CHT_URI_CFLAG_PATH_AND_QUERY)
/* <!-- CHT URI COMPONENTS FLAG --> */

/* <-- CHT URI FORMAT --> */
#define CHT_URI_FORMAT_ESCAPED          (1)
#define CHT_URI_FORMAT_UNESCAPED        (2)
#define CHT_URI_FORMAT_SAFE_UNESCAPED   (3)
/* <!-- CHT URI FORMAT --> */

/* <-- CHT URI IDN SCOPE --> */
#define CHT_URI_IDN_SCOPE_NONE                  (0)
#define CHT_URI_IDN_SCOPE_ALL_EXCEPT_INTRANET   (1)
#define CHT_URI_IDN_SCOPE_ALL                   (3)
/* <!-- CHT URI IDN SCOPE --> */

/* <-- CHT URI PARSING ERRORS --> */
#define CHT_URI_E_NONE                              (0)
#define CHT_URI_E_BAD_FORMAT                        (1)
#define CHT_URI_E_BAD_SCHEME                        (2)
#define CHT_URI_E_BAD_AUTHORITY                     (3)
#define CHT_URI_E_EMPTY_URI_STRING                  (4)
#define CHT_URI_E_SCHEME_LIMIT                      (5)
#define CHT_URI_E_SIZE_LIMIT                        (6)
#define CHT_URI_E_MUST_ROOTED_PATH                  (7)
#define CHT_URI_E_BAD_HOST_NAME                     (8)
#define CHT_URI_E_NON_EMPTY_HOST                    (9)
#define CHT_URI_E_BAD_PORT                          (10)
#define CHT_URI_E_BAD_AUTHORITY_TERMINATOR          (11)
#define CHT_URI_E_CANNOT_CREATE_RELATIVE            (12)
/* <!-- CHT URI PARSING ERRORS --> */

/* fixme: Continue here... */

/* <-- CHT URI DEFAULT SCHEMES --> */
// #define CHT_URI_SCHEME_FILE ""
// #define CHT_URI_SCHEME_
// #define CHT_URI_SCHEME_
// #define CHT_URI_SCHEME_
// #define CHT_URI_SCHEME_
// #define CHT_URI_SCHEME_
// #define CHT_URI_SCHEME_
// #define CHT_URI_SCHEME_
/* <!-- CHT URI DEFAULT SCHEMES --> */

int
cht_uri_parse(cht_uri_t **uri, char const *str_to_parse);

char const *
cht_uri_get_scheme(cht_uri_t const *uri);

char const *
cht_uri_get_host(cht_uri_t const *uri);

char const *
cht_uri_get_path(cht_uri_t const *uri);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CHT_URI_H */
