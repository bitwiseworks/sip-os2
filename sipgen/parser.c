/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 19 "parser.y"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "sip.h"


#define MAX_NESTED_IF       10
#define MAX_NESTED_SCOPE    10

#define inMainModule()      (currentSpec->module == currentModule || currentModule->container != NULL)


static sipSpec *currentSpec;            /* The current spec being parsed. */
static stringList *backstops;           /* The list of backstops. */
static stringList *neededQualifiers;    /* The list of required qualifiers. */
static stringList *excludedQualifiers;  /* The list of excluded qualifiers. */
static moduleDef *currentModule;        /* The current module being parsed. */
static mappedTypeDef *currentMappedType;    /* The current mapped type. */
static enumDef *currentEnum;            /* The current enum being parsed. */
static int sectionFlags;                /* The current section flags. */
static int currentOverIsVirt;           /* Set if the overload is virtual. */
static int currentCtorIsExplicit;       /* Set if the ctor is explicit. */
static int currentIsStatic;             /* Set if the current is static. */
static int currentIsSignal;             /* Set if the current is Q_SIGNAL. */
static int currentIsSlot;               /* Set if the current is Q_SLOT. */
static int currentIsTemplate;           /* Set if the current is a template. */
static char *previousFile;              /* The file just parsed. */
static parserContext currentContext;    /* The current context. */
static int skipStackPtr;                /* The skip stack pointer. */
static int skipStack[MAX_NESTED_IF];    /* Stack of skip flags. */
static classDef *scopeStack[MAX_NESTED_SCOPE];  /* The scope stack. */
static int sectFlagsStack[MAX_NESTED_SCOPE];    /* The section flags stack. */
static int currentScopeIdx;             /* The scope stack index. */
static int currentTimelineOrder;        /* The current timeline order. */
static classList *currentSupers;        /* The current super-class list. */
static KwArgs defaultKwArgs;            /* The default keyword arguments support. */
static int makeProtPublic;              /* Treat protected items as public. */
static int parsingCSignature;           /* An explicit C/C++ signature is being parsed. */


static const char *getPythonName(moduleDef *mod, optFlags *optflgs,
        const char *cname);
static classDef *findClass(sipSpec *pt, ifaceFileType iftype,
        apiVersionRangeDef *api_range, scopedNameDef *fqname);
static classDef *findClassWithInterface(sipSpec *pt, ifaceFileDef *iff);
static classDef *newClass(sipSpec *pt, ifaceFileType iftype,
        apiVersionRangeDef *api_range, scopedNameDef *snd,
        const char *virt_error_handler, typeHintDef *typehint_in,
        typeHintDef *typehint_out, const char *typehint_value);
static void finishClass(sipSpec *, moduleDef *, classDef *, optFlags *);
static exceptionDef *findException(sipSpec *pt, scopedNameDef *fqname, int new);
static mappedTypeDef *newMappedType(sipSpec *,argDef *, optFlags *);
static enumDef *newEnum(sipSpec *pt, moduleDef *mod, mappedTypeDef *mt_scope,
        char *name, optFlags *of, int flags);
static void instantiateClassTemplate(sipSpec *pt, moduleDef *mod,
        classDef *scope, scopedNameDef *fqname, classTmplDef *tcd,
        templateDef *td, const char *pyname);
static void newTypedef(sipSpec *, moduleDef *, char *, argDef *, optFlags *);
static void newVar(sipSpec *pt, moduleDef *mod, char *name, int isstatic,
        argDef *type, optFlags *of, codeBlock *acode, codeBlock *gcode,
        codeBlock *scode, int section);
static void newCtor(moduleDef *, char *, int, signatureDef *, optFlags *,
        codeBlock *, throwArgs *, signatureDef *, int, codeBlock *);
static void newFunction(sipSpec *, moduleDef *, classDef *, mappedTypeDef *,
        int, int, int, int, int, char *, signatureDef *, int, int, optFlags *,
        codeBlock *, codeBlock *, codeBlock *, throwArgs *, signatureDef *,
        codeBlock *);
static optFlag *findOptFlag(optFlags *flgs, const char *name);
static optFlag *getOptFlag(optFlags *flgs, const char *name, flagType ft);
static memberDef *findFunction(sipSpec *, moduleDef *, classDef *,
        mappedTypeDef *, const char *, int, int, int);
static void checkAttributes(sipSpec *, moduleDef *, classDef *,
        mappedTypeDef *, const char *, int);
static void newModule(FILE *fp, const char *filename);
static moduleDef *allocModule();
static void parseFile(FILE *fp, const char *name, moduleDef *prevmod,
        int optional);
static void handleEOF(void);
static void handleEOM(void);
static qualDef *findQualifier(const char *name);
static const char *getInt(const char *cp, int *ip);
static scopedNameDef *text2scopedName(ifaceFileDef *scope, char *text);
static scopedNameDef *scopeScopedName(ifaceFileDef *scope,
        scopedNameDef *name);
static void pushScope(classDef *);
static void popScope(void);
static classDef *currentScope(void);
static void newQualifier(moduleDef *, int, int, int, const char *, qualType);
static qualDef *allocQualifier(moduleDef *, int, int, int, const char *,
        qualType);
static void newImport(const char *filename);
static int timePeriod(const char *lname, const char *uname);
static int platOrFeature(char *,int);
static int notSkipping(void);
static void getHooks(optFlags *,char **,char **);
static int getTransfer(optFlags *optflgs);
static int getReleaseGIL(optFlags *optflgs);
static int getHoldGIL(optFlags *optflgs);
static int getDeprecated(optFlags *optflgs);
static int getAllowNone(optFlags *optflgs);
static int getDisallowNone(optFlags *optflgs);
static const char *getVirtErrorHandler(optFlags *optflgs);
static const char *getDocType(optFlags *optflgs);
static const char *getTypeHintValue(optFlags *optflgs);
static void getTypeHints(optFlags *optflgs, typeHintDef **in,
        typeHintDef **out);
static int getNoTypeHint(optFlags *optflgs);
static void templateSignature(signatureDef *sd, int result, classTmplDef *tcd,
        templateDef *td, classDef *ncd, scopedNameDef *type_names,
        scopedNameDef *type_values);
static void templateType(argDef *ad, classTmplDef *tcd, templateDef *td,
        classDef *ncd, scopedNameDef *type_names, scopedNameDef *type_values);
static int search_back(const char *end, const char *start, const char *target);
static char *type2string(argDef *ad);
static char *scopedNameToString(scopedNameDef *name);
static void addUsedFromCode(sipSpec *pt, ifaceFileList **used, const char *sname);
static int sameName(scopedNameDef *snd, const char *sname);
static int stringFind(stringList *sl, const char *s);
static void setModuleName(sipSpec *pt, moduleDef *mod, const char *fullname);
static int foundInScope(scopedNameDef *fq_name, scopedNameDef *rel_name);
static void defineClass(scopedNameDef *snd, classList *supers, optFlags *of);
static classDef *completeClass(scopedNameDef *snd, optFlags *of, int has_def);
static memberDef *instantiateTemplateMethods(memberDef *tmd, moduleDef *mod);
static void instantiateTemplateEnums(sipSpec *pt, classTmplDef *tcd,
        templateDef *td, classDef *cd, ifaceFileList **used,
        scopedNameDef *type_names, scopedNameDef *type_values);
static void instantiateTemplateVars(sipSpec *pt, classTmplDef *tcd,
        templateDef *td, classDef *cd, ifaceFileList **used,
        scopedNameDef *type_names, scopedNameDef *type_values);
static void instantiateTemplateTypedefs(sipSpec *pt, classTmplDef *tcd,
        templateDef *td, classDef *cd, scopedNameDef *type_names,
        scopedNameDef *type_values);
static overDef *instantiateTemplateOverloads(sipSpec *pt, overDef *tod,
        memberDef *tmethods, memberDef *methods, classTmplDef *tcd,
        templateDef *td, classDef *cd, ifaceFileList **used,
        scopedNameDef *type_names, scopedNameDef *type_values);
static void resolveAnyTypedef(sipSpec *pt, argDef *ad);
static void addTypedef(sipSpec *pt, typedefDef *tdd);
static void addVariable(sipSpec *pt, varDef *vd);
static void applyTypeFlags(moduleDef *mod, argDef *ad, optFlags *flags);
static Format convertFormat(const char *format);
static argType convertEncoding(const char *encoding);
static apiVersionRangeDef *getAPIRange(optFlags *optflgs);
static apiVersionRangeDef *convertAPIRange(moduleDef *mod, nameDef *name,
        int from, int to);
static char *convertFeaturedString(char *fs);
static scopedNameDef *text2scopePart(char *text);
static KwArgs keywordArgs(moduleDef *mod, optFlags *optflgs, signatureDef *sd,
        int need_name);
static char *strip(char *s);
static int isEnabledFeature(const char *name);
static void addProperty(sipSpec *pt, moduleDef *mod, classDef *cd,
        const char *name, const char *get, const char *set,
        codeBlock *docstring);
static moduleDef *configureModule(sipSpec *pt, moduleDef *module,
        const char *filename, const char *name, int version, int c_module,
        KwArgs kwargs, int use_arg_names, int call_super_init,
        int all_raise_py_exc, const char *def_error_handler,
        codeBlock *docstring, const char *nameshort);
static void addAutoPyName(moduleDef *mod, const char *remove_leading);
static KwArgs convertKwArgs(const char *kwargs);
static void checkAnnos(optFlags *annos, const char *valid[]);
static void checkNoAnnos(optFlags *annos, const char *msg);
static void appendCodeBlock(codeBlockList **headp, codeBlock *cb);
static void handleKeepReference(optFlags *optflgs, argDef *ad, moduleDef *mod);
static void mappedTypeAnnos(mappedTypeDef *mtd, optFlags *optflgs);
static void add_new_deref(argDef *new, argDef *orig, int isconst);
static void add_derefs(argDef *dst, argDef *src);
static int isBackstop(qualDef *qd);
static void checkEllipsis(signatureDef *sd);


/* Line 268 of yacc.c  */
#line 246 "../parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_API = 258,
     TK_AUTOPYNAME = 259,
     TK_DEFDOCSTRING = 260,
     TK_DEFENCODING = 261,
     TK_PLUGIN = 262,
     TK_VIRTERRORHANDLER = 263,
     TK_EXPTYPEHINTCODE = 264,
     TK_TYPEHINTCODE = 265,
     TK_DOCSTRING = 266,
     TK_DOC = 267,
     TK_EXPORTEDDOC = 268,
     TK_EXTRACT = 269,
     TK_MAKEFILE = 270,
     TK_ACCESSCODE = 271,
     TK_GETCODE = 272,
     TK_SETCODE = 273,
     TK_PREINITCODE = 274,
     TK_INITCODE = 275,
     TK_POSTINITCODE = 276,
     TK_FINALCODE = 277,
     TK_UNITCODE = 278,
     TK_UNITPOSTINCLUDECODE = 279,
     TK_MODCODE = 280,
     TK_TYPECODE = 281,
     TK_PREPYCODE = 282,
     TK_COPYING = 283,
     TK_MAPPEDTYPE = 284,
     TK_CODELINE = 285,
     TK_IF = 286,
     TK_END = 287,
     TK_NAME_VALUE = 288,
     TK_PATH_VALUE = 289,
     TK_STRING_VALUE = 290,
     TK_VIRTUALCATCHERCODE = 291,
     TK_TRAVERSECODE = 292,
     TK_CLEARCODE = 293,
     TK_GETBUFFERCODE = 294,
     TK_RELEASEBUFFERCODE = 295,
     TK_READBUFFERCODE = 296,
     TK_WRITEBUFFERCODE = 297,
     TK_SEGCOUNTCODE = 298,
     TK_CHARBUFFERCODE = 299,
     TK_PICKLECODE = 300,
     TK_VIRTUALCALLCODE = 301,
     TK_METHODCODE = 302,
     TK_INSTANCECODE = 303,
     TK_FROMTYPE = 304,
     TK_TOTYPE = 305,
     TK_TOSUBCLASS = 306,
     TK_INCLUDE = 307,
     TK_OPTINCLUDE = 308,
     TK_IMPORT = 309,
     TK_EXPHEADERCODE = 310,
     TK_MODHEADERCODE = 311,
     TK_TYPEHEADERCODE = 312,
     TK_MODULE = 313,
     TK_CMODULE = 314,
     TK_CONSMODULE = 315,
     TK_COMPOMODULE = 316,
     TK_CLASS = 317,
     TK_STRUCT = 318,
     TK_PUBLIC = 319,
     TK_PROTECTED = 320,
     TK_PRIVATE = 321,
     TK_SIGNALS = 322,
     TK_SIGNAL_METHOD = 323,
     TK_SLOTS = 324,
     TK_SLOT_METHOD = 325,
     TK_BOOL = 326,
     TK_SHORT = 327,
     TK_INT = 328,
     TK_LONG = 329,
     TK_FLOAT = 330,
     TK_DOUBLE = 331,
     TK_CHAR = 332,
     TK_WCHAR_T = 333,
     TK_VOID = 334,
     TK_PYOBJECT = 335,
     TK_PYTUPLE = 336,
     TK_PYLIST = 337,
     TK_PYDICT = 338,
     TK_PYCALLABLE = 339,
     TK_PYSLICE = 340,
     TK_PYTYPE = 341,
     TK_PYBUFFER = 342,
     TK_VIRTUAL = 343,
     TK_ENUM = 344,
     TK_SIGNED = 345,
     TK_UNSIGNED = 346,
     TK_SCOPE = 347,
     TK_LOGICAL_OR = 348,
     TK_CONST = 349,
     TK_STATIC = 350,
     TK_SIPSIGNAL = 351,
     TK_SIPSLOT = 352,
     TK_SIPANYSLOT = 353,
     TK_SIPRXCON = 354,
     TK_SIPRXDIS = 355,
     TK_SIPSLOTCON = 356,
     TK_SIPSLOTDIS = 357,
     TK_SIPSSIZET = 358,
     TK_NUMBER_VALUE = 359,
     TK_REAL_VALUE = 360,
     TK_TYPEDEF = 361,
     TK_NAMESPACE = 362,
     TK_TIMELINE = 363,
     TK_PLATFORMS = 364,
     TK_FEATURE = 365,
     TK_LICENSE = 366,
     TK_QCHAR_VALUE = 367,
     TK_TRUE_VALUE = 368,
     TK_FALSE_VALUE = 369,
     TK_NULL_VALUE = 370,
     TK_OPERATOR = 371,
     TK_THROW = 372,
     TK_QOBJECT = 373,
     TK_EXCEPTION = 374,
     TK_RAISECODE = 375,
     TK_VIRTERRORCODE = 376,
     TK_EXPLICIT = 377,
     TK_TEMPLATE = 378,
     TK_ELLIPSIS = 379,
     TK_DEFMETATYPE = 380,
     TK_DEFSUPERTYPE = 381,
     TK_PROPERTY = 382,
     TK_FORMAT = 383,
     TK_GET = 384,
     TK_ID = 385,
     TK_KWARGS = 386,
     TK_LANGUAGE = 387,
     TK_LICENSEE = 388,
     TK_NAME = 389,
     TK_OPTIONAL = 390,
     TK_ORDER = 391,
     TK_REMOVELEADING = 392,
     TK_SET = 393,
     TK_SIGNATURE = 394,
     TK_TIMESTAMP = 395,
     TK_TYPE = 396,
     TK_USEARGNAMES = 397,
     TK_ALLRAISEPYEXC = 398,
     TK_CALLSUPERINIT = 399,
     TK_DEFERRORHANDLER = 400,
     TK_VERSION = 401,
     TK_NAMESHORT = 402
   };
#endif
/* Tokens.  */
#define TK_API 258
#define TK_AUTOPYNAME 259
#define TK_DEFDOCSTRING 260
#define TK_DEFENCODING 261
#define TK_PLUGIN 262
#define TK_VIRTERRORHANDLER 263
#define TK_EXPTYPEHINTCODE 264
#define TK_TYPEHINTCODE 265
#define TK_DOCSTRING 266
#define TK_DOC 267
#define TK_EXPORTEDDOC 268
#define TK_EXTRACT 269
#define TK_MAKEFILE 270
#define TK_ACCESSCODE 271
#define TK_GETCODE 272
#define TK_SETCODE 273
#define TK_PREINITCODE 274
#define TK_INITCODE 275
#define TK_POSTINITCODE 276
#define TK_FINALCODE 277
#define TK_UNITCODE 278
#define TK_UNITPOSTINCLUDECODE 279
#define TK_MODCODE 280
#define TK_TYPECODE 281
#define TK_PREPYCODE 282
#define TK_COPYING 283
#define TK_MAPPEDTYPE 284
#define TK_CODELINE 285
#define TK_IF 286
#define TK_END 287
#define TK_NAME_VALUE 288
#define TK_PATH_VALUE 289
#define TK_STRING_VALUE 290
#define TK_VIRTUALCATCHERCODE 291
#define TK_TRAVERSECODE 292
#define TK_CLEARCODE 293
#define TK_GETBUFFERCODE 294
#define TK_RELEASEBUFFERCODE 295
#define TK_READBUFFERCODE 296
#define TK_WRITEBUFFERCODE 297
#define TK_SEGCOUNTCODE 298
#define TK_CHARBUFFERCODE 299
#define TK_PICKLECODE 300
#define TK_VIRTUALCALLCODE 301
#define TK_METHODCODE 302
#define TK_INSTANCECODE 303
#define TK_FROMTYPE 304
#define TK_TOTYPE 305
#define TK_TOSUBCLASS 306
#define TK_INCLUDE 307
#define TK_OPTINCLUDE 308
#define TK_IMPORT 309
#define TK_EXPHEADERCODE 310
#define TK_MODHEADERCODE 311
#define TK_TYPEHEADERCODE 312
#define TK_MODULE 313
#define TK_CMODULE 314
#define TK_CONSMODULE 315
#define TK_COMPOMODULE 316
#define TK_CLASS 317
#define TK_STRUCT 318
#define TK_PUBLIC 319
#define TK_PROTECTED 320
#define TK_PRIVATE 321
#define TK_SIGNALS 322
#define TK_SIGNAL_METHOD 323
#define TK_SLOTS 324
#define TK_SLOT_METHOD 325
#define TK_BOOL 326
#define TK_SHORT 327
#define TK_INT 328
#define TK_LONG 329
#define TK_FLOAT 330
#define TK_DOUBLE 331
#define TK_CHAR 332
#define TK_WCHAR_T 333
#define TK_VOID 334
#define TK_PYOBJECT 335
#define TK_PYTUPLE 336
#define TK_PYLIST 337
#define TK_PYDICT 338
#define TK_PYCALLABLE 339
#define TK_PYSLICE 340
#define TK_PYTYPE 341
#define TK_PYBUFFER 342
#define TK_VIRTUAL 343
#define TK_ENUM 344
#define TK_SIGNED 345
#define TK_UNSIGNED 346
#define TK_SCOPE 347
#define TK_LOGICAL_OR 348
#define TK_CONST 349
#define TK_STATIC 350
#define TK_SIPSIGNAL 351
#define TK_SIPSLOT 352
#define TK_SIPANYSLOT 353
#define TK_SIPRXCON 354
#define TK_SIPRXDIS 355
#define TK_SIPSLOTCON 356
#define TK_SIPSLOTDIS 357
#define TK_SIPSSIZET 358
#define TK_NUMBER_VALUE 359
#define TK_REAL_VALUE 360
#define TK_TYPEDEF 361
#define TK_NAMESPACE 362
#define TK_TIMELINE 363
#define TK_PLATFORMS 364
#define TK_FEATURE 365
#define TK_LICENSE 366
#define TK_QCHAR_VALUE 367
#define TK_TRUE_VALUE 368
#define TK_FALSE_VALUE 369
#define TK_NULL_VALUE 370
#define TK_OPERATOR 371
#define TK_THROW 372
#define TK_QOBJECT 373
#define TK_EXCEPTION 374
#define TK_RAISECODE 375
#define TK_VIRTERRORCODE 376
#define TK_EXPLICIT 377
#define TK_TEMPLATE 378
#define TK_ELLIPSIS 379
#define TK_DEFMETATYPE 380
#define TK_DEFSUPERTYPE 381
#define TK_PROPERTY 382
#define TK_FORMAT 383
#define TK_GET 384
#define TK_ID 385
#define TK_KWARGS 386
#define TK_LANGUAGE 387
#define TK_LICENSEE 388
#define TK_NAME 389
#define TK_OPTIONAL 390
#define TK_ORDER 391
#define TK_REMOVELEADING 392
#define TK_SET 393
#define TK_SIGNATURE 394
#define TK_TIMESTAMP 395
#define TK_TYPE 396
#define TK_USEARGNAMES 397
#define TK_ALLRAISEPYEXC 398
#define TK_CALLSUPERINIT 399
#define TK_DEFERRORHANDLER 400
#define TK_VERSION 401
#define TK_NAMESHORT 402




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 193 "parser.y"

    char            qchar;
    char            *text;
    long            number;
    double          real;
    argDef          memArg;
    signatureDef    signature;
    signatureDef    *optsignature;
    throwArgs       *throwlist;
    codeBlock       *codeb;
    valueDef        value;
    valueDef        *valp;
    optFlags        optflags;
    optFlag         flag;
    scopedNameDef   *scpvalp;
    fcallDef        fcall;
    int             boolean;
    exceptionDef    exceptionbase;
    classDef        *klass;
    apiCfg          api;
    autoPyNameCfg   autopyname;
    compModuleCfg   compmodule;
    consModuleCfg   consmodule;
    defDocstringCfg defdocstring;
    defEncodingCfg  defencoding;
    defMetatypeCfg  defmetatype;
    defSupertypeCfg defsupertype;
    exceptionCfg    exception;
    docstringCfg    docstring;
    extractCfg      extract;
    featureCfg      feature;
    licenseCfg      license;
    importCfg       import;
    includeCfg      include;
    moduleCfg       module;
    pluginCfg       plugin;
    propertyCfg     property;
    variableCfg     variable;
    vehCfg          veh;
    int             token;



/* Line 293 of yacc.c  */
#line 620 "../parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 632 "../parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1600

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  170
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  241
/* YYNRULES -- Number of rules.  */
#define YYNRULES  567
/* YYNRULES -- Number of states.  */
#define YYNSTATES  991

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   402

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   155,     2,     2,     2,   168,   160,     2,
     148,   149,   158,   157,   150,   156,     2,   159,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   165,   154,
     163,   151,   164,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   166,     2,   167,   169,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   152,   161,   153,   162,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    48,    50,    52,    54,    56,    58,
      60,    62,    64,    66,    68,    70,    72,    74,    76,    78,
      80,    82,    84,    86,    88,    90,    92,    94,    96,    98,
     100,   102,   104,   106,   108,   111,   113,   117,   119,   123,
     127,   130,   132,   136,   138,   142,   146,   149,   151,   155,
     157,   161,   165,   169,   171,   175,   177,   181,   185,   188,
     191,   195,   197,   201,   205,   209,   215,   216,   220,   225,
     227,   230,   232,   234,   236,   238,   241,   242,   248,   249,
     256,   261,   263,   266,   268,   270,   272,   274,   277,   280,
     282,   284,   286,   300,   301,   307,   308,   312,   314,   317,
     318,   324,   326,   329,   331,   334,   336,   340,   342,   346,
     350,   351,   357,   359,   362,   364,   369,   371,   374,   378,
     383,   385,   389,   391,   395,   396,   398,   402,   404,   408,
     412,   416,   420,   424,   427,   429,   433,   435,   439,   443,
     446,   448,   452,   454,   458,   462,   466,   468,   472,   474,
     478,   482,   483,   488,   490,   493,   495,   497,   499,   503,
     505,   509,   511,   515,   519,   520,   525,   527,   530,   532,
     534,   536,   540,   544,   545,   549,   553,   555,   559,   563,
     567,   571,   575,   579,   583,   587,   591,   595,   596,   601,
     603,   606,   608,   610,   612,   614,   616,   618,   619,   621,
     624,   626,   630,   632,   636,   640,   644,   647,   650,   652,
     656,   658,   662,   666,   667,   670,   671,   674,   675,   678,
     681,   684,   687,   690,   693,   696,   699,   702,   705,   708,
     711,   714,   717,   720,   723,   726,   729,   732,   735,   738,
     741,   744,   747,   750,   753,   756,   759,   762,   765,   769,
     771,   775,   779,   783,   784,   786,   790,   792,   796,   800,
     801,   803,   807,   809,   813,   815,   819,   823,   827,   832,
     835,   837,   840,   841,   850,   851,   853,   854,   856,   857,
     859,   861,   864,   866,   868,   873,   874,   876,   877,   880,
     881,   884,   886,   890,   892,   894,   896,   898,   900,   902,
     903,   905,   907,   909,   911,   913,   915,   919,   920,   924,
     926,   930,   932,   934,   936,   938,   943,   945,   947,   949,
     951,   953,   955,   956,   958,   962,   968,   980,   981,   982,
     991,   992,   996,  1001,  1002,  1003,  1012,  1013,  1016,  1018,
    1022,  1025,  1026,  1028,  1030,  1032,  1033,  1037,  1039,  1042,
    1044,  1046,  1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,
    1064,  1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,  1082,
    1084,  1086,  1088,  1090,  1092,  1094,  1096,  1099,  1102,  1105,
    1109,  1113,  1117,  1120,  1124,  1128,  1130,  1134,  1138,  1142,
    1146,  1147,  1152,  1154,  1157,  1159,  1161,  1163,  1165,  1167,
    1168,  1170,  1182,  1183,  1187,  1189,  1200,  1201,  1202,  1209,
    1210,  1211,  1219,  1220,  1222,  1238,  1246,  1262,  1277,  1279,
    1281,  1283,  1285,  1287,  1289,  1291,  1293,  1296,  1299,  1302,
    1305,  1308,  1311,  1314,  1317,  1320,  1323,  1327,  1331,  1333,
    1336,  1339,  1341,  1344,  1347,  1350,  1352,  1355,  1356,  1358,
    1359,  1362,  1363,  1367,  1369,  1373,  1375,  1379,  1381,  1387,
    1389,  1391,  1392,  1395,  1396,  1399,  1400,  1403,  1405,  1406,
    1408,  1412,  1417,  1422,  1427,  1431,  1435,  1442,  1449,  1453,
    1456,  1457,  1461,  1462,  1466,  1468,  1469,  1473,  1475,  1477,
    1479,  1480,  1484,  1486,  1495,  1496,  1500,  1502,  1505,  1507,
    1509,  1512,  1515,  1518,  1523,  1527,  1531,  1532,  1534,  1535,
    1539,  1542,  1544,  1549,  1552,  1555,  1557,  1559,  1562,  1564,
    1566,  1569,  1572,  1576,  1578,  1580,  1582,  1585,  1588,  1590,
    1592,  1594,  1596,  1598,  1600,  1602,  1604,  1606,  1608,  1610,
    1612,  1614,  1616,  1620,  1621,  1626,  1627,  1629
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     171,     0,    -1,   172,    -1,   171,   172,    -1,    -1,   173,
     174,    -1,   256,    -1,   242,    -1,   249,    -1,   184,    -1,
     278,    -1,   266,    -1,   270,    -1,   271,    -1,   192,    -1,
     222,    -1,   214,    -1,   218,    -1,   230,    -1,   176,    -1,
     180,    -1,   234,    -1,   238,    -1,   279,    -1,   280,    -1,
     293,    -1,   295,    -1,   296,    -1,   297,    -1,   298,    -1,
     299,    -1,   300,    -1,   301,    -1,   302,    -1,   304,    -1,
     305,    -1,   315,    -1,   319,    -1,   202,    -1,   204,    -1,
     188,    -1,   175,    -1,   226,    -1,   229,    -1,   210,    -1,
     343,    -1,   349,    -1,   346,    -1,   196,    -1,   342,    -1,
     322,    -1,   377,    -1,   399,    -1,   281,    -1,     5,   177,
      -1,    35,    -1,   148,   178,   149,    -1,   179,    -1,   178,
     150,   179,    -1,   134,   151,    35,    -1,     6,   181,    -1,
      35,    -1,   148,   182,   149,    -1,   183,    -1,   182,   150,
     183,    -1,   134,   151,    35,    -1,     7,   185,    -1,    33,
      -1,   148,   186,   149,    -1,   187,    -1,   186,   150,   187,
      -1,   134,   151,    33,    -1,     8,   189,   320,    -1,    33,
      -1,   148,   190,   149,    -1,   191,    -1,   190,   150,   191,
      -1,   134,   151,    33,    -1,     3,   193,    -1,    33,   104,
      -1,   148,   194,   149,    -1,   195,    -1,   194,   150,   195,
      -1,   134,   151,   366,    -1,   146,   151,   104,    -1,   119,
     337,   197,   381,   198,    -1,    -1,   148,   337,   149,    -1,
     152,   199,   153,   154,    -1,   200,    -1,   199,   200,    -1,
     226,    -1,   229,    -1,   201,    -1,   281,    -1,   120,   320,
      -1,    -1,    29,   407,   381,   203,   206,    -1,    -1,   348,
      29,   407,   381,   205,   206,    -1,   152,   207,   153,   154,
      -1,   208,    -1,   207,   208,    -1,   226,    -1,   229,    -1,
     281,    -1,   294,    -1,    49,   320,    -1,    50,   320,    -1,
     290,    -1,   322,    -1,   209,    -1,    95,   403,    33,   148,
     388,   149,   379,   409,   381,   374,   154,   314,   386,    -1,
      -1,   107,    33,   211,   212,   154,    -1,    -1,   152,   213,
     153,    -1,   175,    -1,   213,   175,    -1,    -1,   109,   215,
     152,   216,   153,    -1,   217,    -1,   216,   217,    -1,    33,
      -1,   110,   219,    -1,    33,    -1,   148,   220,   149,    -1,
     221,    -1,   220,   150,   221,    -1,   134,   151,   366,    -1,
      -1,   108,   223,   152,   224,   153,    -1,   225,    -1,   224,
     225,    -1,    33,    -1,    31,   148,   228,   149,    -1,    33,
      -1,   155,    33,    -1,   227,    93,    33,    -1,   227,    93,
     155,    33,    -1,   227,    -1,   325,   156,   325,    -1,    32,
      -1,   111,   231,   381,    -1,    -1,    35,    -1,   148,   232,
     149,    -1,   233,    -1,   232,   150,   233,    -1,   141,   151,
      35,    -1,   133,   151,    35,    -1,   139,   151,    35,    -1,
     140,   151,    35,    -1,   125,   235,    -1,   264,    -1,   148,
     236,   149,    -1,   237,    -1,   236,   150,   237,    -1,   134,
     151,   264,    -1,   126,   239,    -1,   264,    -1,   148,   240,
     149,    -1,   241,    -1,   240,   150,   241,    -1,   134,   151,
     264,    -1,    60,   243,   246,    -1,   264,    -1,   148,   244,
     149,    -1,   245,    -1,   244,   150,   245,    -1,   134,   151,
     264,    -1,    -1,   152,   247,   153,   154,    -1,   248,    -1,
     247,   248,    -1,   226,    -1,   229,    -1,   310,    -1,    61,
     250,   253,    -1,   264,    -1,   148,   251,   149,    -1,   252,
      -1,   251,   150,   252,    -1,   134,   151,   264,    -1,    -1,
     152,   254,   153,   154,    -1,   255,    -1,   254,   255,    -1,
     226,    -1,   229,    -1,   310,    -1,    58,   257,   261,    -1,
      59,   264,   265,    -1,    -1,   264,   258,   265,    -1,   148,
     259,   149,    -1,   260,    -1,   259,   150,   260,    -1,   131,
     151,    35,    -1,   132,   151,    35,    -1,   134,   151,   264,
      -1,   147,   151,   264,    -1,   142,   151,   339,    -1,   143,
     151,   339,    -1,   144,   151,   339,    -1,   145,   151,    33,
      -1,   146,   151,   104,    -1,    -1,   152,   262,   153,   154,
      -1,   263,    -1,   262,   263,    -1,   226,    -1,   229,    -1,
     306,    -1,   310,    -1,    33,    -1,    34,    -1,    -1,   104,
      -1,    52,   267,    -1,    34,    -1,   148,   268,   149,    -1,
     269,    -1,   268,   150,   269,    -1,   134,   151,    34,    -1,
     135,   151,   339,    -1,    53,    34,    -1,    54,   272,    -1,
      34,    -1,   148,   273,   149,    -1,   274,    -1,   273,   150,
     274,    -1,   134,   151,    34,    -1,    -1,    16,   320,    -1,
      -1,    17,   320,    -1,    -1,    18,   320,    -1,    28,   320,
      -1,    55,   320,    -1,    56,   320,    -1,    57,   320,    -1,
      37,   320,    -1,    38,   320,    -1,    39,   320,    -1,    40,
     320,    -1,    41,   320,    -1,    42,   320,    -1,    43,   320,
      -1,    44,   320,    -1,    48,   320,    -1,    45,   320,    -1,
      22,   320,    -1,    25,   320,    -1,    26,   320,    -1,    19,
     320,    -1,    20,   320,    -1,    21,   320,    -1,    23,   320,
      -1,    24,   320,    -1,    27,   320,    -1,     9,   320,    -1,
      10,   320,    -1,    10,   320,    -1,    12,   320,    -1,    13,
     320,    -1,     4,   307,    -1,   148,   308,   149,    -1,   309,
      -1,   308,   150,   309,    -1,   137,   151,    35,    -1,    11,
     311,   320,    -1,    -1,    35,    -1,   148,   312,   149,    -1,
     313,    -1,   312,   150,   313,    -1,   128,   151,    35,    -1,
      -1,   310,    -1,    14,   316,   320,    -1,    33,    -1,   148,
     317,   149,    -1,   318,    -1,   317,   150,   318,    -1,   130,
     151,    33,    -1,   136,   151,   104,    -1,    15,    34,   324,
     320,    -1,   321,    32,    -1,    30,    -1,   321,    30,    -1,
      -1,    89,   325,   381,   323,   152,   326,   153,   154,    -1,
      -1,    34,    -1,    -1,    33,    -1,    -1,   327,    -1,   328,
      -1,   327,   328,    -1,   226,    -1,   229,    -1,    33,   330,
     381,   329,    -1,    -1,   150,    -1,    -1,   151,   335,    -1,
      -1,   151,   332,    -1,   335,    -1,   332,   333,   335,    -1,
     156,    -1,   157,    -1,   158,    -1,   159,    -1,   160,    -1,
     161,    -1,    -1,   155,    -1,   162,    -1,   156,    -1,   157,
      -1,   158,    -1,   160,    -1,   336,   334,   340,    -1,    -1,
     148,   337,   149,    -1,   338,    -1,   337,    92,   338,    -1,
      33,    -1,   113,    -1,   114,    -1,   337,    -1,   407,   148,
     341,   149,    -1,   105,    -1,   104,    -1,   339,    -1,   115,
      -1,    35,    -1,   112,    -1,    -1,   332,    -1,   341,   150,
     332,    -1,   106,   403,    33,   381,   154,    -1,   106,   403,
     148,   158,    33,   149,   148,   408,   149,   381,   154,    -1,
      -1,    -1,    63,   337,   344,   352,   381,   345,   356,   154,
      -1,    -1,   348,   347,   349,    -1,   123,   163,   408,   164,
      -1,    -1,    -1,    62,   337,   350,   352,   381,   351,   356,
     154,    -1,    -1,   165,   353,    -1,   354,    -1,   353,   150,
     354,    -1,   355,   337,    -1,    -1,    64,    -1,    65,    -1,
      66,    -1,    -1,   152,   357,   153,    -1,   358,    -1,   357,
     358,    -1,   226,    -1,   229,    -1,   210,    -1,   343,    -1,
     349,    -1,   196,    -1,   342,    -1,   322,    -1,   359,    -1,
     310,    -1,   294,    -1,   281,    -1,   282,    -1,   283,    -1,
     284,    -1,   285,    -1,   286,    -1,   287,    -1,   288,    -1,
     289,    -1,   290,    -1,   291,    -1,   292,    -1,   303,    -1,
     369,    -1,   368,    -1,   391,    -1,    51,   320,    -1,    50,
     320,    -1,    49,   320,    -1,    64,   367,   165,    -1,    65,
     367,   165,    -1,    66,   367,   165,    -1,    67,   165,    -1,
     127,   360,   363,    -1,   148,   361,   149,    -1,   362,    -1,
     361,   150,   362,    -1,   129,   151,    33,    -1,   134,   151,
     366,    -1,   138,   151,    33,    -1,    -1,   152,   364,   153,
     154,    -1,   365,    -1,   364,   365,    -1,   226,    -1,   229,
      -1,   310,    -1,    33,    -1,    35,    -1,    -1,    69,    -1,
     376,   162,    33,   148,   149,   409,   380,   381,   154,   386,
     387,    -1,    -1,   122,   370,   371,    -1,   371,    -1,    33,
     148,   388,   149,   409,   381,   372,   154,   314,   386,    -1,
      -1,    -1,   166,   373,   148,   388,   149,   167,    -1,    -1,
      -1,   166,   375,   403,   148,   388,   149,   167,    -1,    -1,
      88,    -1,   403,    33,   148,   388,   149,   379,   409,   380,
     381,   374,   154,   314,   386,   387,   385,    -1,   403,   116,
     151,   148,   403,   149,   154,    -1,   403,   116,   378,   148,
     388,   149,   379,   409,   380,   381,   374,   154,   386,   387,
     385,    -1,   116,   403,   148,   388,   149,   379,   409,   380,
     381,   374,   154,   386,   387,   385,    -1,   157,    -1,   156,
      -1,   158,    -1,   159,    -1,   168,    -1,   160,    -1,   161,
      -1,   169,    -1,   163,   163,    -1,   164,   164,    -1,   157,
     151,    -1,   156,   151,    -1,   158,   151,    -1,   159,   151,
      -1,   168,   151,    -1,   160,   151,    -1,   161,   151,    -1,
     169,   151,    -1,   163,   163,   151,    -1,   164,   164,   151,
      -1,   162,    -1,   148,   149,    -1,   166,   167,    -1,   163,
      -1,   163,   151,    -1,   151,   151,    -1,   155,   151,    -1,
     164,    -1,   164,   151,    -1,    -1,    94,    -1,    -1,   151,
     104,    -1,    -1,   159,   382,   159,    -1,   383,    -1,   382,
     150,   383,    -1,    33,    -1,    33,   151,   384,    -1,   264,
      -1,    33,   165,   265,   156,   265,    -1,    35,    -1,   104,
      -1,    -1,    46,   320,    -1,    -1,    47,   320,    -1,    -1,
      36,   320,    -1,   389,    -1,    -1,   390,    -1,   389,   150,
     390,    -1,    96,   325,   381,   331,    -1,    97,   325,   381,
     331,    -1,    98,   325,   381,   331,    -1,    99,   325,   381,
      -1,   100,   325,   381,    -1,   101,   148,   388,   149,   325,
     381,    -1,   102,   148,   388,   149,   325,   381,    -1,   118,
     325,   381,    -1,   404,   331,    -1,    -1,    68,   392,   394,
      -1,    -1,    70,   393,   394,    -1,   394,    -1,    -1,    95,
     395,   396,    -1,   396,    -1,   397,    -1,   399,    -1,    -1,
      88,   398,   377,    -1,   377,    -1,   403,    33,   381,   400,
     154,   275,   276,   277,    -1,    -1,   152,   401,   153,    -1,
     402,    -1,   401,   402,    -1,   226,    -1,   229,    -1,    16,
     320,    -1,    17,   320,    -1,    18,   320,    -1,    94,   407,
     406,   405,    -1,   407,   406,   405,    -1,   403,   325,   381,
      -1,    -1,   160,    -1,    -1,   406,   158,    94,    -1,   406,
     158,    -1,   337,    -1,   337,   163,   408,   164,    -1,    63,
     337,    -1,    91,    72,    -1,    72,    -1,    91,    -1,    91,
      73,    -1,    73,    -1,    74,    -1,    91,    74,    -1,    74,
      74,    -1,    91,    74,    74,    -1,    75,    -1,    76,    -1,
      71,    -1,    90,    77,    -1,    91,    77,    -1,    77,    -1,
      78,    -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,
     103,    -1,   124,    -1,   403,    -1,   408,   150,   403,    -1,
      -1,   117,   148,   410,   149,    -1,    -1,   337,    -1,   410,
     150,   337,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   547,   547,   548,   551,   551,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   632,   638,   643,   648,   649,   659,
     666,   675,   680,   685,   686,   696,   703,   711,   716,   721,
     722,   732,   739,   768,   773,   778,   779,   789,   796,   822,
     830,   835,   836,   847,   853,   861,   911,   915,  1022,  1027,
    1028,  1039,  1042,  1045,  1059,  1075,  1080,  1080,  1103,  1103,
    1168,  1182,  1183,  1186,  1187,  1188,  1192,  1196,  1205,  1214,
    1223,  1224,  1227,  1241,  1241,  1278,  1279,  1282,  1283,  1286,
    1286,  1315,  1316,  1319,  1325,  1331,  1336,  1341,  1342,  1352,
    1359,  1359,  1385,  1386,  1389,  1395,  1408,  1411,  1414,  1417,
    1422,  1423,  1428,  1434,  1471,  1479,  1485,  1490,  1491,  1504,
    1512,  1520,  1528,  1538,  1549,  1554,  1559,  1560,  1570,  1577,
    1588,  1593,  1598,  1599,  1609,  1616,  1636,  1641,  1646,  1647,
    1657,  1664,  1668,  1673,  1674,  1684,  1687,  1690,  1704,  1722,
    1727,  1732,  1733,  1743,  1750,  1754,  1759,  1760,  1770,  1773,
    1776,  1790,  1801,  1811,  1811,  1825,  1830,  1831,  1849,  1862,
    1881,  1894,  1907,  1920,  1933,  1946,  1959,  1977,  1981,  1986,
    1987,  1997,  2000,  2003,  2006,  2020,  2021,  2037,  2040,  2043,
    2052,  2058,  2063,  2064,  2075,  2081,  2089,  2097,  2103,  2108,
    2113,  2114,  2124,  2131,  2134,  2139,  2142,  2147,  2150,  2155,
    2161,  2167,  2173,  2178,  2183,  2188,  2193,  2198,  2203,  2208,
    2213,  2218,  2223,  2228,  2233,  2239,  2244,  2250,  2256,  2262,
    2268,  2274,  2279,  2285,  2291,  2296,  2302,  2308,  2314,  2319,
    2320,  2330,  2337,  2417,  2420,  2425,  2430,  2431,  2441,  2448,
    2451,  2454,  2463,  2469,  2474,  2475,  2486,  2492,  2503,  2508,
    2511,  2512,  2522,  2522,  2543,  2546,  2551,  2554,  2559,  2560,
    2563,  2564,  2567,  2568,  2569,  2607,  2608,  2611,  2612,  2615,
    2618,  2623,  2624,  2642,  2645,  2648,  2651,  2654,  2657,  2662,
    2665,  2668,  2671,  2674,  2677,  2680,  2685,  2700,  2703,  2708,
    2709,  2717,  2722,  2725,  2730,  2739,  2749,  2753,  2757,  2761,
    2765,  2769,  2775,  2780,  2786,  2804,  2826,  2865,  2871,  2865,
    2914,  2914,  2940,  2945,  2951,  2945,  2990,  2991,  2994,  2995,
    2998,  3042,  3045,  3048,  3051,  3056,  3059,  3064,  3065,  3068,
    3069,  3070,  3071,  3072,  3073,  3074,  3075,  3076,  3077,  3081,
    3085,  3089,  3100,  3111,  3122,  3133,  3144,  3155,  3166,  3177,
    3188,  3199,  3210,  3221,  3222,  3223,  3224,  3235,  3246,  3257,
    3264,  3271,  3278,  3287,  3300,  3305,  3306,  3318,  3325,  3332,
    3341,  3345,  3350,  3351,  3361,  3364,  3367,  3381,  3382,  3385,
    3388,  3393,  3455,  3455,  3456,  3459,  3505,  3508,  3508,  3519,
    3522,  3522,  3534,  3537,  3542,  3560,  3580,  3616,  3697,  3698,
    3699,  3700,  3701,  3702,  3703,  3704,  3705,  3706,  3707,  3708,
    3709,  3710,  3711,  3712,  3713,  3714,  3715,  3716,  3717,  3718,
    3719,  3720,  3721,  3722,  3723,  3724,  3725,  3728,  3731,  3736,
    3739,  3747,  3750,  3756,  3760,  3772,  3776,  3782,  3786,  3809,
    3813,  3819,  3822,  3827,  3830,  3835,  3838,  3843,  3895,  3900,
    3906,  3929,  3941,  3953,  3965,  3984,  3995,  4012,  4029,  4038,
    4045,  4045,  4046,  4046,  4047,  4051,  4051,  4052,  4056,  4057,
    4061,  4061,  4062,  4065,  4120,  4126,  4131,  4132,  4144,  4147,
    4150,  4165,  4180,  4197,  4202,  4216,  4319,  4322,  4330,  4333,
    4336,  4341,  4349,  4360,  4375,  4379,  4383,  4387,  4391,  4395,
    4399,  4403,  4407,  4411,  4415,  4419,  4423,  4427,  4431,  4435,
    4439,  4443,  4447,  4451,  4455,  4459,  4463,  4467,  4471,  4475,
    4479,  4485,  4491,  4507,  4510,  4518,  4524,  4531
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_API", "TK_AUTOPYNAME",
  "TK_DEFDOCSTRING", "TK_DEFENCODING", "TK_PLUGIN", "TK_VIRTERRORHANDLER",
  "TK_EXPTYPEHINTCODE", "TK_TYPEHINTCODE", "TK_DOCSTRING", "TK_DOC",
  "TK_EXPORTEDDOC", "TK_EXTRACT", "TK_MAKEFILE", "TK_ACCESSCODE",
  "TK_GETCODE", "TK_SETCODE", "TK_PREINITCODE", "TK_INITCODE",
  "TK_POSTINITCODE", "TK_FINALCODE", "TK_UNITCODE",
  "TK_UNITPOSTINCLUDECODE", "TK_MODCODE", "TK_TYPECODE", "TK_PREPYCODE",
  "TK_COPYING", "TK_MAPPEDTYPE", "TK_CODELINE", "TK_IF", "TK_END",
  "TK_NAME_VALUE", "TK_PATH_VALUE", "TK_STRING_VALUE",
  "TK_VIRTUALCATCHERCODE", "TK_TRAVERSECODE", "TK_CLEARCODE",
  "TK_GETBUFFERCODE", "TK_RELEASEBUFFERCODE", "TK_READBUFFERCODE",
  "TK_WRITEBUFFERCODE", "TK_SEGCOUNTCODE", "TK_CHARBUFFERCODE",
  "TK_PICKLECODE", "TK_VIRTUALCALLCODE", "TK_METHODCODE",
  "TK_INSTANCECODE", "TK_FROMTYPE", "TK_TOTYPE", "TK_TOSUBCLASS",
  "TK_INCLUDE", "TK_OPTINCLUDE", "TK_IMPORT", "TK_EXPHEADERCODE",
  "TK_MODHEADERCODE", "TK_TYPEHEADERCODE", "TK_MODULE", "TK_CMODULE",
  "TK_CONSMODULE", "TK_COMPOMODULE", "TK_CLASS", "TK_STRUCT", "TK_PUBLIC",
  "TK_PROTECTED", "TK_PRIVATE", "TK_SIGNALS", "TK_SIGNAL_METHOD",
  "TK_SLOTS", "TK_SLOT_METHOD", "TK_BOOL", "TK_SHORT", "TK_INT", "TK_LONG",
  "TK_FLOAT", "TK_DOUBLE", "TK_CHAR", "TK_WCHAR_T", "TK_VOID",
  "TK_PYOBJECT", "TK_PYTUPLE", "TK_PYLIST", "TK_PYDICT", "TK_PYCALLABLE",
  "TK_PYSLICE", "TK_PYTYPE", "TK_PYBUFFER", "TK_VIRTUAL", "TK_ENUM",
  "TK_SIGNED", "TK_UNSIGNED", "TK_SCOPE", "TK_LOGICAL_OR", "TK_CONST",
  "TK_STATIC", "TK_SIPSIGNAL", "TK_SIPSLOT", "TK_SIPANYSLOT",
  "TK_SIPRXCON", "TK_SIPRXDIS", "TK_SIPSLOTCON", "TK_SIPSLOTDIS",
  "TK_SIPSSIZET", "TK_NUMBER_VALUE", "TK_REAL_VALUE", "TK_TYPEDEF",
  "TK_NAMESPACE", "TK_TIMELINE", "TK_PLATFORMS", "TK_FEATURE",
  "TK_LICENSE", "TK_QCHAR_VALUE", "TK_TRUE_VALUE", "TK_FALSE_VALUE",
  "TK_NULL_VALUE", "TK_OPERATOR", "TK_THROW", "TK_QOBJECT", "TK_EXCEPTION",
  "TK_RAISECODE", "TK_VIRTERRORCODE", "TK_EXPLICIT", "TK_TEMPLATE",
  "TK_ELLIPSIS", "TK_DEFMETATYPE", "TK_DEFSUPERTYPE", "TK_PROPERTY",
  "TK_FORMAT", "TK_GET", "TK_ID", "TK_KWARGS", "TK_LANGUAGE",
  "TK_LICENSEE", "TK_NAME", "TK_OPTIONAL", "TK_ORDER", "TK_REMOVELEADING",
  "TK_SET", "TK_SIGNATURE", "TK_TIMESTAMP", "TK_TYPE", "TK_USEARGNAMES",
  "TK_ALLRAISEPYEXC", "TK_CALLSUPERINIT", "TK_DEFERRORHANDLER",
  "TK_VERSION", "TK_NAMESHORT", "'('", "')'", "','", "'='", "'{'", "'}'",
  "';'", "'!'", "'-'", "'+'", "'*'", "'/'", "'&'", "'|'", "'~'", "'<'",
  "'>'", "':'", "'['", "']'", "'%'", "'^'", "$accept", "specification",
  "statement", "$@1", "modstatement", "nsstatement", "defdocstring",
  "defdocstring_args", "defdocstring_arg_list", "defdocstring_arg",
  "defencoding", "defencoding_args", "defencoding_arg_list",
  "defencoding_arg", "plugin", "plugin_args", "plugin_arg_list",
  "plugin_arg", "virterrorhandler", "veh_args", "veh_arg_list", "veh_arg",
  "api", "api_args", "api_arg_list", "api_arg", "exception",
  "baseexception", "exception_body", "exception_body_directives",
  "exception_body_directive", "raisecode", "mappedtype", "$@2",
  "mappedtypetmpl", "$@3", "mtdefinition", "mtbody", "mtline",
  "mtfunction", "namespace", "$@4", "optnsbody", "nsbody", "platforms",
  "$@5", "platformlist", "platform", "feature", "feature_args",
  "feature_arg_list", "feature_arg", "timeline", "$@6", "qualifierlist",
  "qualifiername", "ifstart", "oredqualifiers", "qualifiers", "ifend",
  "license", "license_args", "license_arg_list", "license_arg",
  "defmetatype", "defmetatype_args", "defmetatype_arg_list",
  "defmetatype_arg", "defsupertype", "defsupertype_args",
  "defsupertype_arg_list", "defsupertype_arg", "consmodule",
  "consmodule_args", "consmodule_arg_list", "consmodule_arg",
  "consmodule_body", "consmodule_body_directives",
  "consmodule_body_directive", "compmodule", "compmodule_args",
  "compmodule_arg_list", "compmodule_arg", "compmodule_body",
  "compmodule_body_directives", "compmodule_body_directive", "module",
  "module_args", "$@7", "module_arg_list", "module_arg", "module_body",
  "module_body_directives", "module_body_directive", "dottedname",
  "optnumber", "include", "include_args", "include_arg_list",
  "include_arg", "optinclude", "import", "import_args", "import_arg_list",
  "import_arg", "optaccesscode", "optgetcode", "optsetcode", "copying",
  "exphdrcode", "modhdrcode", "typehdrcode", "travcode", "clearcode",
  "getbufcode", "releasebufcode", "readbufcode", "writebufcode",
  "segcountcode", "charbufcode", "instancecode", "picklecode", "finalcode",
  "modcode", "typecode", "preinitcode", "initcode", "postinitcode",
  "unitcode", "unitpostinccode", "prepycode", "exptypehintcode",
  "modtypehintcode", "classtypehintcode", "doc", "exporteddoc",
  "autopyname", "autopyname_args", "autopyname_arg_list", "autopyname_arg",
  "docstring", "docstring_args", "docstring_arg_list", "docstring_arg",
  "optdocstring", "extract", "extract_args", "extract_arg_list",
  "extract_arg", "makefile", "codeblock", "codelines", "enum", "$@8",
  "optfilename", "optname", "optenumbody", "enumbody", "enumline",
  "optcomma", "optenumassign", "optassign", "expr", "binop", "optunop",
  "value", "optcast", "scopedname", "scopepart", "bool_value",
  "simplevalue", "exprlist", "typedef", "struct", "$@9", "$@10",
  "classtmpl", "$@11", "template", "class", "$@12", "$@13", "superclasses",
  "superlist", "superclass", "class_access", "optclassbody", "classbody",
  "classline", "property", "property_args", "property_arg_list",
  "property_arg", "property_body", "property_body_directives",
  "property_body_directive", "name_or_string", "optslot", "dtor", "ctor",
  "$@14", "simplector", "optctorsig", "$@15", "optsig", "$@16",
  "optvirtual", "function", "operatorname", "optconst", "optabstract",
  "optflags", "flaglist", "flag", "flagvalue", "virtualcallcode",
  "methodcode", "virtualcatchercode", "arglist", "rawarglist", "argvalue",
  "varmember", "$@17", "$@18", "simple_varmem", "$@19", "varmem", "member",
  "$@20", "variable", "variable_body", "variable_body_directives",
  "variable_body_directive", "cpptype", "argtype", "optref", "deref",
  "basetype", "cpptypelist", "optexceptions", "exceptionlist", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,    40,    41,
      44,    61,   123,   125,    59,    33,    45,    43,    42,    47,
      38,   124,   126,    60,    62,    58,    91,    93,    37,    94
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   170,   171,   171,   173,   172,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   176,   177,   177,   178,   178,   179,
     180,   181,   181,   182,   182,   183,   184,   185,   185,   186,
     186,   187,   188,   189,   189,   190,   190,   191,   192,   193,
     193,   194,   194,   195,   195,   196,   197,   197,   198,   199,
     199,   200,   200,   200,   200,   201,   203,   202,   205,   204,
     206,   207,   207,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   209,   211,   210,   212,   212,   213,   213,   215,
     214,   216,   216,   217,   218,   219,   219,   220,   220,   221,
     223,   222,   224,   224,   225,   226,   227,   227,   227,   227,
     228,   228,   229,   230,   231,   231,   231,   232,   232,   233,
     233,   233,   233,   234,   235,   235,   236,   236,   237,   238,
     239,   239,   240,   240,   241,   242,   243,   243,   244,   244,
     245,   246,   246,   247,   247,   248,   248,   248,   249,   250,
     250,   251,   251,   252,   253,   253,   254,   254,   255,   255,
     255,   256,   256,   258,   257,   257,   259,   259,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   261,   261,   262,
     262,   263,   263,   263,   263,   264,   264,   265,   265,   266,
     267,   267,   268,   268,   269,   269,   270,   271,   272,   272,
     273,   273,   274,   275,   275,   276,   276,   277,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     308,   309,   310,   311,   311,   311,   312,   312,   313,   314,
     314,   315,   316,   316,   317,   317,   318,   318,   319,   320,
     321,   321,   323,   322,   324,   324,   325,   325,   326,   326,
     327,   327,   328,   328,   328,   329,   329,   330,   330,   331,
     331,   332,   332,   333,   333,   333,   333,   333,   333,   334,
     334,   334,   334,   334,   334,   334,   335,   336,   336,   337,
     337,   338,   339,   339,   340,   340,   340,   340,   340,   340,
     340,   340,   341,   341,   341,   342,   342,   344,   345,   343,
     347,   346,   348,   350,   351,   349,   352,   352,   353,   353,
     354,   355,   355,   355,   355,   356,   356,   357,   357,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   359,   360,   361,   361,   362,   362,   362,
     363,   363,   364,   364,   365,   365,   365,   366,   366,   367,
     367,   368,   370,   369,   369,   371,   372,   373,   372,   374,
     375,   374,   376,   376,   377,   377,   377,   377,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   379,   379,   380,
     380,   381,   381,   382,   382,   383,   383,   384,   384,   384,
     384,   385,   385,   386,   386,   387,   387,   388,   389,   389,
     389,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     392,   391,   393,   391,   391,   395,   394,   394,   396,   396,
     398,   397,   397,   399,   400,   400,   401,   401,   402,   402,
     402,   402,   402,   403,   403,   404,   405,   405,   406,   406,
     406,   407,   407,   407,   407,   407,   407,   407,   407,   407,
     407,   407,   407,   407,   407,   407,   407,   407,   407,   407,
     407,   407,   407,   407,   407,   407,   407,   407,   407,   407,
     407,   408,   408,   409,   409,   410,   410,   410
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     3,     3,
       2,     1,     3,     1,     3,     3,     2,     1,     3,     1,
       3,     3,     3,     1,     3,     1,     3,     3,     2,     2,
       3,     1,     3,     3,     3,     5,     0,     3,     4,     1,
       2,     1,     1,     1,     1,     2,     0,     5,     0,     6,
       4,     1,     2,     1,     1,     1,     1,     2,     2,     1,
       1,     1,    13,     0,     5,     0,     3,     1,     2,     0,
       5,     1,     2,     1,     2,     1,     3,     1,     3,     3,
       0,     5,     1,     2,     1,     4,     1,     2,     3,     4,
       1,     3,     1,     3,     0,     1,     3,     1,     3,     3,
       3,     3,     3,     2,     1,     3,     1,     3,     3,     2,
       1,     3,     1,     3,     3,     3,     1,     3,     1,     3,
       3,     0,     4,     1,     2,     1,     1,     1,     3,     1,
       3,     1,     3,     3,     0,     4,     1,     2,     1,     1,
       1,     3,     3,     0,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     0,     4,     1,
       2,     1,     1,     1,     1,     1,     1,     0,     1,     2,
       1,     3,     1,     3,     3,     3,     2,     2,     1,     3,
       1,     3,     3,     0,     2,     0,     2,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     1,
       3,     3,     3,     0,     1,     3,     1,     3,     3,     0,
       1,     3,     1,     3,     1,     3,     3,     3,     4,     2,
       1,     2,     0,     8,     0,     1,     0,     1,     0,     1,
       1,     2,     1,     1,     4,     0,     1,     0,     2,     0,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     3,     0,     3,     1,
       3,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     0,     1,     3,     5,    11,     0,     0,     8,
       0,     3,     4,     0,     0,     8,     0,     2,     1,     3,
       2,     0,     1,     1,     1,     0,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     3,
       3,     3,     2,     3,     3,     1,     3,     3,     3,     3,
       0,     4,     1,     2,     1,     1,     1,     1,     1,     0,
       1,    11,     0,     3,     1,    10,     0,     0,     6,     0,
       0,     7,     0,     1,    15,     7,    15,    14,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     3,     1,     2,
       2,     1,     2,     2,     2,     1,     2,     0,     1,     0,
       2,     0,     3,     1,     3,     1,     3,     1,     5,     1,
       1,     0,     2,     0,     2,     0,     2,     1,     0,     1,
       3,     4,     4,     4,     3,     3,     6,     6,     3,     2,
       0,     3,     0,     3,     1,     0,     3,     1,     1,     1,
       0,     3,     1,     8,     0,     3,     1,     2,     1,     1,
       2,     2,     2,     4,     3,     3,     0,     1,     0,     3,
       2,     1,     4,     2,     2,     1,     1,     2,     1,     1,
       2,     2,     3,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     4,     0,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     4,     2,     0,     1,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   331,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   545,   535,   538,   539,   543,   544,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   296,     0,
     536,     0,   559,     0,     0,   130,   119,     0,   144,     0,
       0,     0,   560,     0,     0,     5,    41,    19,    20,     9,
      40,    14,    48,    38,    39,    44,    16,    17,    15,    42,
      43,    18,    21,    22,     7,     8,     6,    11,    12,    13,
      10,    23,    24,    53,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    50,   531,   329,
      49,    45,    47,   350,    46,    51,    52,     0,   528,     0,
       0,    78,    55,     0,    54,    61,     0,    60,    67,     0,
      66,    73,     0,     0,   290,   262,     0,   263,   265,   266,
     282,     0,     0,   294,   256,   257,   258,   259,   260,   254,
     261,   239,     0,   471,   296,   220,     0,   219,   226,   228,
       0,   227,   240,   241,   242,   215,   216,     0,   207,   193,
     217,     0,   171,   166,     0,   184,   179,   353,   347,   541,
     297,   471,   546,   534,   537,   540,   547,   528,     0,   113,
       0,     0,   125,     0,   124,   145,     0,   471,     0,    86,
       0,     0,   153,   154,     0,   159,   160,     0,     0,     0,
       0,   471,     0,   526,    79,     0,     0,     0,    81,     0,
       0,    57,     0,     0,    63,     0,     0,    69,     0,     0,
      75,    72,   291,   289,     0,     0,     0,   284,   281,   295,
       0,   533,     0,    96,   136,     0,   140,     0,     0,     0,
       0,     0,   222,     0,     0,   230,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   196,     0,   191,   217,
     218,   192,     0,     0,   168,     0,   165,     0,     0,   181,
       0,   178,   356,   356,   292,   542,   526,   471,     0,   115,
       0,     0,     0,     0,   127,     0,     0,     0,     0,     0,
     147,   143,   488,     0,   471,   561,     0,     0,     0,   156,
       0,     0,   162,   330,     0,   471,   351,   488,   514,     0,
       0,     0,   439,   438,   440,   441,   443,   444,   458,   461,
     465,     0,   442,   445,     0,   530,   527,   524,     0,     0,
      80,     0,     0,    56,     0,     0,    62,     0,     0,    68,
       0,     0,    74,     0,     0,     0,   283,     0,   288,   475,
       0,   473,     0,   137,     0,   135,   296,     0,     0,   221,
       0,     0,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   195,     0,     0,   273,   211,   212,     0,
     209,   213,   214,   194,     0,   167,     0,   175,   176,     0,
     173,   177,     0,   180,     0,   188,   189,     0,   186,   190,
     361,   471,   471,     0,   523,     0,     0,     0,     0,   134,
       0,   132,   123,     0,   121,     0,   126,     0,     0,     0,
       0,     0,   146,     0,   296,   296,   296,   296,   296,     0,
       0,   296,     0,   487,   489,   296,   309,     0,     0,     0,
     352,     0,   155,     0,     0,   161,     0,   532,    98,     0,
       0,     0,   459,     0,   463,   464,   449,   448,   450,   451,
     453,   454,   462,   446,   466,   447,   460,   452,   455,   488,
     529,   417,   418,    83,    84,    82,    59,    58,    65,    64,
      71,    70,    77,    76,   286,   287,   285,     0,     0,   472,
       0,    97,   138,     0,   141,   224,   332,   333,   225,   223,
     232,   231,   198,   199,   200,   202,   203,   204,   205,   206,
     201,   197,     0,   267,   274,     0,     0,     0,   210,   170,
     169,     0,   174,   183,   182,     0,   187,   362,   363,   364,
     357,   358,     0,   354,   348,   298,   345,     0,   117,     0,
     350,   114,   131,   133,   120,   122,   129,   128,   150,   151,
     152,   149,   148,   471,   471,   471,   471,   471,   488,   488,
     471,   467,     0,   471,   327,   499,    87,     0,    85,   562,
     158,   157,   164,   163,     0,   467,     0,     0,     0,   518,
     519,     0,   516,   233,     0,   456,   457,     0,   215,   479,
     480,   477,   476,   474,     0,     0,     0,     0,     0,     0,
     101,   111,   103,   104,   105,   109,   106,   110,   139,     0,
       0,   269,     0,     0,   276,   272,   208,   172,   185,   361,
     360,   365,   365,   307,   302,   303,     0,   299,   300,     0,
     116,   118,   309,   309,   309,   494,   495,     0,     0,   498,
     468,   563,   490,   525,     0,   310,   311,   319,     0,     0,
      89,    93,    91,    92,    94,    99,   563,   520,   521,   522,
     515,   517,     0,   235,     0,   467,   217,   255,   251,   107,
     108,     0,     0,   102,     0,   268,     0,     0,   275,     0,
     359,   432,     0,     0,   327,   471,     0,   301,     0,   491,
     492,   493,   296,   296,     0,   469,     0,   313,   314,   315,
     316,   317,   318,   327,   320,   322,   323,   324,   325,   321,
       0,    95,     0,    90,   469,   234,     0,   237,   435,   563,
       0,     0,   100,   271,   270,   278,   277,     0,     0,   331,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   419,   419,   419,     0,   500,   502,   510,   505,
     422,     0,   374,   371,   369,   370,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   379,   392,
     378,   376,   375,   372,   373,   432,   367,   377,   394,   393,
     424,     0,   512,   395,   504,   507,   508,   509,   355,   349,
     308,   305,   293,     0,   471,   471,   565,     0,   471,   328,
     312,   340,   337,   336,   341,   339,   334,   338,   326,     0,
      88,   471,   236,     0,   513,   469,   217,   488,   264,   253,
     488,   243,   244,   245,   246,   247,   248,   249,   250,   252,
     398,   397,   396,   420,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,   410,   366,   368,     0,   306,   304,
     471,   496,   497,   566,     0,   470,   429,   327,   429,   238,
     471,   478,     0,     0,   399,   400,   401,   510,   501,   503,
     511,     0,   506,     0,   423,     0,     0,     0,     0,   405,
       0,   403,     0,     0,   564,     0,   430,     0,   343,     0,
       0,   429,   467,   563,     0,     0,     0,     0,   404,     0,
     414,   415,   416,     0,   412,     0,   346,   567,     0,   483,
     335,   327,   279,     0,   563,   471,   407,   408,   409,   406,
       0,   413,   563,     0,     0,   485,   344,   280,   483,   483,
     471,   426,   411,   469,   488,   484,     0,   481,   485,   485,
     429,   427,     0,   471,     0,   486,     0,   437,   481,   481,
       0,     0,   279,     0,     0,   482,   434,   436,   279,   488,
     483,   483,   431,   483,     0,   425,   485,   112,     0,   421,
     428
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     3,    75,    76,    77,   134,   230,   231,
      78,   137,   233,   234,    79,   140,   236,   237,    80,   143,
     239,   240,    81,   131,   227,   228,    82,   314,   588,   669,
     670,   671,    83,   372,    84,   594,   511,   619,   620,   621,
      85,   299,   428,   559,    86,   201,   433,   434,    87,   204,
     303,   304,    88,   200,   430,   431,    89,   256,   257,    90,
      91,   207,   309,   310,    92,   212,   318,   319,    93,   215,
     321,   322,    94,   182,   283,   284,   286,   409,   410,    95,
     185,   288,   289,   291,   417,   418,    96,   178,   279,   275,
     276,   278,   399,   400,   179,   281,    97,   167,   261,   262,
      98,    99,   171,   264,   265,   683,   737,   834,   100,   101,
     102,   103,   777,   778,   779,   780,   781,   782,   783,   784,
     625,   786,   787,   104,   626,   105,   106,   107,   108,   109,
     110,   111,   112,   789,   113,   114,   401,   533,   630,   631,
     947,   536,   633,   634,   948,   115,   152,   246,   247,   116,
     145,   146,   117,   423,   250,   191,   646,   647,   648,   869,
     705,   585,   665,   723,   730,   666,   667,   118,   119,   518,
     828,   909,   120,   121,   293,   642,   122,   220,   560,   124,
     292,   641,   421,   550,   551,   552,   702,   795,   796,   797,
     864,   898,   899,   901,   923,   924,   493,   854,   798,   799,
     862,   800,   962,   971,   907,   928,   801,   802,   344,   661,
     818,   253,   370,   371,   612,   967,   945,   957,   452,   453,
     454,   803,   858,   859,   804,   861,   805,   806,   860,   807,
     471,   601,   602,   455,   456,   347,   223,   128,   316,   715,
     874
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -775
static const yytype_int16 yypact[] =
{
    -775,    48,  -775,  1021,  -775,  -775,    32,    52,    61,    41,
      79,    65,    65,    65,    65,    80,    99,    65,    65,    65,
      65,    65,    65,    65,    65,   609,    42,  -775,  -775,    27,
     130,    39,    65,    65,    65,    55,   231,    57,    60,   161,
     161,  -775,  -775,  -775,   175,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,   199,   192,
     216,   609,  -775,   311,   239,  -775,  -775,    81,    69,   311,
     161,   113,  -775,    68,    72,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,   -13,  -775,
    -775,  -775,  -775,   257,  -775,  -775,  -775,    25,  -775,   200,
      19,  -775,  -775,   183,  -775,  -775,   191,  -775,  -775,   198,
    -775,  -775,   211,    65,  -775,  -775,   271,  -775,  -775,  -775,
    -775,    76,    65,   336,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,   161,   222,    16,  -775,   187,  -775,  -775,  -775,
     285,  -775,  -775,  -775,  -775,  -775,  -775,   215,   221,  -775,
     330,   326,   263,  -775,   340,   293,  -775,   384,     8,  -775,
    -775,   222,  -775,  -775,  -775,   405,  -775,  -775,    82,  -775,
     328,   329,  -775,   348,  -775,  -775,   158,   222,   335,    31,
     311,   350,  -775,  -775,   352,  -775,  -775,   161,   311,   609,
     425,    56,   359,   217,  -775,   337,   339,   188,  -775,   341,
     206,  -775,   342,   230,  -775,   345,   254,  -775,   346,   262,
    -775,  -775,  -775,  -775,   349,   351,   268,  -775,  -775,  -775,
      65,   384,   456,  -775,   347,   458,   401,   355,   353,   354,
     357,   275,  -775,   360,   279,  -775,   361,   379,   380,   382,
     383,   385,   386,   388,   389,   281,  -775,   247,  -775,   330,
    -775,  -775,   391,   283,  -775,   214,  -775,   392,   287,  -775,
     214,  -775,   334,   334,  -775,  -775,   217,   222,   377,   393,
     468,   511,   395,   291,  -775,   398,   399,   400,   402,   294,
    -775,  -775,  1249,   161,   222,  -775,   -21,   403,   298,  -775,
     404,   300,  -775,  -775,   -16,   222,  -775,  1249,   406,   407,
     109,   409,   410,   411,   412,   413,   414,   415,  -775,    33,
      86,   390,   416,   417,   422,   478,  -775,  -775,   343,   448,
    -775,    19,   540,  -775,   183,   541,  -775,   191,   544,  -775,
     198,   545,  -775,   211,   549,   479,  -775,    76,  -775,   436,
     -33,  -775,   437,  -775,    17,  -775,   199,   554,   338,  -775,
     187,   556,  -775,   285,   557,   558,   231,   338,   338,   338,
     561,   487,   231,  -775,   215,   447,    83,  -775,  -775,    35,
    -775,  -775,  -775,  -775,   231,  -775,   326,  -775,  -775,    44,
    -775,  -775,   231,  -775,   340,  -775,  -775,    46,  -775,  -775,
     245,   222,   222,   444,  -775,   443,   565,  1194,   445,  -775,
      14,  -775,  -775,    23,  -775,   343,  -775,   348,   566,   571,
     572,   573,  -775,   158,   199,   199,   199,   199,   199,   452,
     461,   199,   462,   460,  -775,   199,   463,   -24,   464,   311,
    -775,   231,  -775,   350,   231,  -775,   352,  -775,  -775,   466,
     264,   459,  -775,   311,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,   469,  -775,   470,  -775,  -775,  -775,  1249,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,   201,   456,  -775,
     235,  -775,  -775,   579,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,   480,  -775,  -775,   491,    65,   471,  -775,  -775,
    -775,   472,  -775,  -775,  -775,   473,  -775,  -775,  -775,  -775,
     474,  -775,   161,  -775,  -775,   303,  -775,   481,  -775,   729,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,   222,   222,   222,   222,   222,  1249,  1249,
     222,   528,  1249,   222,   475,  -775,  -775,   128,  -775,  -775,
    -775,  -775,  -775,  -775,   437,   528,    65,    65,    65,  -775,
    -775,    66,  -775,   612,   482,  -775,  -775,   483,   476,  -775,
    -775,  -775,  -775,  -775,    65,    65,    65,    65,   311,   106,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,   484,
     306,  -775,   485,   308,  -775,  -775,  -775,  -775,  -775,   245,
     384,   477,   477,   486,  -775,  -775,   490,   303,  -775,   492,
    -775,  -775,   463,   463,   463,  -775,  -775,   495,   496,  -775,
    -775,   516,  -775,  -775,   161,   207,  -775,   171,    65,    54,
    -775,  -775,  -775,  -775,  -775,  -775,   516,  -775,  -775,  -775,
    -775,  -775,    65,   617,   500,   528,   330,  -775,  -775,  -775,
    -775,   606,   501,  -775,   614,  -775,   480,   615,  -775,   491,
    -775,  1128,   503,   504,   475,   222,   505,  -775,   311,  -775,
    -775,  -775,   199,   199,   512,   510,    90,  -775,  -775,  -775,
    -775,  -775,  -775,   475,  -775,  -775,  -775,  -775,  -775,  -775,
    1309,  -775,   508,  -775,   510,  -775,    65,   645,  -775,   516,
     509,   518,  -775,  -775,  -775,  -775,  -775,    65,    65,   519,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,   599,   599,   599,   513,  -775,  -775,   507,  -775,
    -775,   525,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,   898,  -775,  -775,  -775,  -775,
    -775,   515,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,   529,  -775,   312,   222,   222,   161,   594,   222,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,    30,  -775,  -775,   559,
    -775,   222,  -775,    65,  -775,   510,   330,  1249,  -775,  -775,
    1249,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,   537,   546,   550,  -775,  1364,  1364,
    1476,  1420,   672,   118,   562,  -775,  -775,   673,  -775,  -775,
     222,  -775,  -775,   384,   314,  -775,   543,   193,   543,  -775,
     222,  -775,   567,   568,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,    29,  -775,   519,  -775,   569,   570,   574,   316,  -775,
     214,  -775,   575,   564,  -775,   161,  -775,   576,   207,   318,
     577,   543,   528,   516,   578,   677,   343,   686,  -775,   118,
    -775,  -775,  -775,    49,  -775,   580,  -775,   384,   311,   680,
    -775,   475,   717,   583,   516,   222,  -775,  -775,  -775,  -775,
     596,  -775,   516,   584,    65,   698,   207,  -775,   680,   680,
     222,   585,  -775,   510,  1249,  -775,    65,   706,   698,   698,
     543,  -775,   600,   222,   604,  -775,    65,  -775,   706,   706,
     601,   608,   717,   603,   591,  -775,  -775,  -775,   717,  1249,
     680,   680,  -775,   680,   610,  -775,   698,  -775,   597,  -775,
    -775
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -775,  -775,   762,  -775,  -775,  -382,  -775,  -775,  -775,   418,
    -775,  -775,  -775,   408,  -775,  -775,  -775,   419,  -775,  -775,
    -775,   421,  -775,  -775,  -775,   420,  -649,  -775,  -775,  -775,
      97,  -775,  -775,  -775,  -775,  -775,   173,  -775,   150,  -775,
    -609,  -775,  -775,  -775,  -775,  -775,  -775,   344,  -775,  -775,
    -775,   333,  -775,  -775,  -775,   358,  -248,  -775,  -775,  -247,
    -775,  -775,  -775,   331,  -775,  -775,  -775,   310,  -775,  -775,
    -775,   309,  -775,  -775,  -775,   370,  -775,  -775,   369,  -775,
    -775,  -775,   366,  -775,  -775,   364,  -775,  -775,  -775,  -775,
     423,  -775,  -775,   394,    34,  -263,  -775,  -775,  -775,   442,
    -775,  -775,  -775,  -775,   441,  -775,  -775,  -775,  -775,  -775,
    -775,  -477,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -582,  -775,  -775,  -775,  -581,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,    89,
    -226,  -775,  -775,    88,  -672,  -775,  -775,  -775,   427,  -775,
     -12,  -775,  -475,  -775,  -775,  -132,  -775,  -775,   135,  -775,
    -775,  -302,  -774,  -775,  -775,  -595,  -775,   -26,   581,  -361,
    -775,  -775,  -574,  -562,  -775,  -775,  -775,  -775,   786,  -216,
    -775,  -775,   506,  -775,   186,  -775,   155,  -775,    36,  -775,
    -775,  -775,   -93,  -775,  -775,   -96,  -410,  -294,  -775,  -775,
    -775,   -34,  -775,  -775,  -762,  -775,  -775,    12,  -775,  -564,
    -700,  -167,  -775,   321,  -775,  -497,  -706,  -718,  -308,  -775,
     248,  -775,  -775,  -775,  -381,  -775,   -28,  -775,  -775,    15,
    -775,  -775,   233,     0,  -775,   542,   640,    -8,  -195,  -640,
    -775
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -534
static const yytype_int16 yytable[] =
{
     147,   148,   149,   127,   326,   154,   155,   156,   157,   158,
     159,   160,   161,   187,   188,   125,   403,   163,   126,   469,
     172,   173,   174,   324,   294,   566,   525,   526,   527,   397,
     398,   676,   258,   624,   831,   627,   734,   407,   408,   395,
     311,  -533,   415,   416,   209,   558,   396,   429,     4,   254,
     512,   402,   772,   197,   328,   396,   432,   396,   221,   411,
     396,   165,   914,   198,   419,   129,    26,    27,   217,   208,
     180,   183,   186,   169,   138,    26,    27,    26,    27,   217,
      26,    27,   596,   597,   598,    26,    27,   132,   175,   176,
     175,   176,   773,   175,   176,   144,   135,    26,    27,   835,
     217,   175,   176,   908,   205,   175,   176,   213,   216,   810,
     674,    34,   141,   150,   202,   297,   910,   508,   534,   785,
     788,   739,   217,   217,  -533,   586,   509,   792,   820,   459,
     425,   241,   614,   153,   459,   880,   251,    26,    27,   793,
     248,   222,   624,   460,   627,   222,   772,   458,   467,   933,
     218,   397,   398,   225,   615,   616,   617,   946,   468,    26,
      27,   407,   408,    34,   168,   226,  -533,   562,  -533,   415,
     416,   255,   513,   402,   668,   166,   564,   651,  -531,   313,
     130,   607,   217,   411,   482,    34,   773,   170,   537,   139,
     164,   419,   674,   218,    28,    58,   483,   541,   970,   545,
     133,   618,   940,   177,   327,   181,   244,   732,   184,   136,
     315,   325,   245,   785,   788,   252,   211,   206,   315,   680,
     214,   792,   599,   600,   776,   396,   791,   142,   151,   203,
     298,   535,   190,   793,   608,   176,   609,   484,   368,   819,
     968,   969,   958,   959,   514,    26,    27,   895,   668,   189,
     485,   395,   896,   963,   553,   554,   897,   473,   396,   692,
     474,   614,   622,   623,   175,   176,    26,    27,   989,   192,
     657,   658,   199,   935,   985,   986,   210,   987,    26,    27,
     596,   597,   598,   615,   616,   617,   219,   457,   193,   194,
     195,   305,    34,   196,   950,    26,    27,   306,   307,   308,
     980,   242,   953,   243,   224,   610,   983,   644,   645,   547,
     548,   549,   573,   574,   575,   576,   577,   229,   776,   580,
     791,   259,   260,   583,    58,   232,   724,   725,   726,   727,
     618,   728,   235,   729,    26,    27,   643,   350,   351,   672,
     673,   664,  -342,  -342,    28,   238,   266,   267,   934,   268,
     709,   710,   711,   599,   600,   353,   354,   269,   270,   271,
     272,   273,   274,   717,   718,   719,   720,   721,   722,   827,
     249,   622,   623,   277,   162,   345,   491,   346,   492,   356,
     357,   252,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,   644,
     645,    59,    60,   359,   360,    61,   652,   653,   654,   655,
     656,   362,   363,   659,    62,   285,   663,   366,   367,   263,
     524,   672,   673,   740,   379,   380,   530,   127,   382,   383,
     393,   394,   405,   406,   280,    72,   413,   414,   539,   125,
     436,   437,   126,   442,   443,   290,   543,   462,   463,   465,
     466,   516,   517,   774,   775,   695,   696,   698,   699,   589,
     282,   870,   459,   904,   905,   918,   919,   930,   931,   855,
     856,   976,   977,   604,   287,   790,   217,   888,   889,   295,
     300,   301,   302,   312,   317,   794,   320,    39,   348,   369,
     349,   373,   352,   355,   374,   590,   358,   361,   592,   420,
     364,   429,   365,  -297,   375,   377,   937,   329,   378,   376,
     330,   381,   384,   813,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   635,   341,   640,   342,   343,   882,
     385,   386,   883,   387,   388,   426,   389,   390,   811,   391,
     392,   611,   404,   412,   432,   427,   435,   774,   775,   438,
     439,   440,   494,   441,   461,   464,   472,   486,   470,   127,
     475,   476,   477,   478,   479,   480,   481,   487,   488,   790,
     489,   125,   490,   881,   126,   496,   498,   500,   502,   794,
     814,   815,   504,   505,   677,   678,   679,   507,   515,   510,
     520,   529,   522,   523,   528,   532,   555,   556,   557,   561,
     578,   568,   687,   688,   689,   690,   569,   570,   571,   579,
     582,   581,   628,   603,   584,   595,   587,   629,   691,   632,
     605,   606,   660,   664,   639,   636,   637,   638,   682,   701,
     649,   684,   685,   714,   736,   694,   697,   704,   716,   741,
     708,   686,    28,   706,   712,   713,   964,   871,   872,   743,
     745,   876,   920,   921,   738,   742,   731,   808,   809,   812,
     816,   817,   830,   833,   878,   836,   837,   840,   853,  -433,
     735,   984,   162,   863,   922,   920,   921,   867,   857,   868,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   922,   875,    59,
      60,   127,   884,   903,   826,   893,   902,   877,   315,   906,
     936,   885,    62,   911,   900,   886,   912,   913,   926,   938,
     915,   916,   829,   925,   832,   917,   327,   944,   396,   942,
     929,   932,   954,    72,   956,   838,   839,   949,   841,   842,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
     952,   961,   966,   974,   972,   978,   979,   981,   982,   988,
      26,    27,    28,     5,   990,   499,   733,   675,   951,   693,
     567,   495,   497,   591,   572,   593,   540,   565,   542,   501,
     544,   546,   707,   960,   503,   744,    34,   746,   563,   123,
     873,    39,    40,   538,   506,   127,   973,   703,   323,   422,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   531,    58,    59,
      60,   879,   519,    61,   521,   700,   939,   941,   894,   613,
     662,   866,    62,   892,   681,    63,    64,   296,   424,     0,
       0,     0,     0,     0,     0,    69,     0,     0,    70,     0,
       0,     0,    71,    72,     0,     0,     0,     0,   127,   127,
     891,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   890,     0,     0,     0,     0,     0,     0,   927,
       0,     0,   650,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   747,   396,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     748,     0,     0,     0,   614,     0,     0,     0,   943,    26,
      27,   749,   955,     0,     0,   750,   751,   752,   753,   754,
     755,   756,   757,   758,   965,     0,   615,   759,   760,   761,
       0,     0,     0,     0,   975,    34,     0,     0,     0,     0,
      39,    40,   762,   763,   764,   765,   766,     0,   767,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   768,    58,    59,    60,
       0,     0,    61,   769,     0,     0,     0,     0,     0,     0,
       0,    62,     0,     0,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,    69,     0,     0,    70,     0,     0,
     770,     0,    72,     0,     6,   771,     7,     8,     9,    10,
      11,    12,     0,    13,    14,    15,    16,     0,     0,     0,
      17,    18,    19,     0,    20,    21,    22,     0,    23,    24,
      25,   865,    26,    27,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,     0,     0,     0,     0,
       0,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
      58,    59,    60,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     0,    63,    64,    65,
      66,    67,    68,     0,     0,     0,     0,    69,   747,   396,
      70,     0,     0,     0,    71,    72,    73,    74,     0,     0,
     748,     0,     0,     0,   614,     0,     0,     0,     0,    26,
      27,   749,     0,     0,     0,   750,   751,   752,   753,   754,
     755,   756,   757,   758,     0,     0,   615,   759,   760,   761,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
      39,    40,   762,   763,   764,   765,   766,     0,   767,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   768,    58,    59,    60,
       0,     0,    61,   769,     0,    26,    27,    28,     0,     0,
       0,    62,     0,     0,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,    69,     0,     0,    70,     0,     0,
     770,    34,    72,     0,     0,   771,    39,    40,     0,     0,
       0,     0,     0,     0,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    28,    58,    59,    60,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     0,     0,    62,     0,     0,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,   162,    70,     0,     0,     0,    71,    72,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,     0,    59,
      60,     0,    28,    61,   821,   444,   445,   446,   447,   448,
     449,   450,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   451,     0,     0,
       0,     0,   162,    72,     0,     0,     0,     0,     0,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    28,     0,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,   822,   823,     0,     0,     0,     0,     0,
       0,   824,   516,   517,   825,     0,     0,   162,     0,     0,
       0,     0,     0,    72,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,   887,    28,    59,    60,     0,     0,    61,   769,
       0,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,     0,   162,     0,     0,     0,     0,    72,     0,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,   887,    28,
      59,    60,     0,     0,    61,     0,     0,     0,     0,     0,
       0,     0,     0,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,     0,   162,
       0,     0,     0,     0,    72,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,     0,    59,    60,     0,     0,
      61,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,     0,     0,     0,     0,     0,     0,
      72
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-775))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      12,    13,    14,     3,   220,    17,    18,    19,    20,    21,
      22,    23,    24,    39,    40,     3,   279,    25,     3,   327,
      32,    33,    34,   218,   191,   435,   387,   388,   389,   277,
     277,   595,   164,   510,   734,   510,   676,   285,   285,     4,
     207,    33,   290,   290,    70,   427,    11,    33,     0,    33,
      33,   277,   701,    61,   221,    11,    33,    11,    33,   285,
      11,    34,    33,    63,   290,    33,    31,    32,    92,    69,
      36,    37,    38,    34,    33,    31,    32,    31,    32,    92,
      31,    32,    16,    17,    18,    31,    32,    35,    33,    34,
      33,    34,   701,    33,    34,    30,    35,    31,    32,   739,
      92,    33,    34,   877,    35,    33,    34,    73,    74,   704,
     587,    57,    33,    33,    33,    33,   878,   150,    35,   701,
     701,   685,    92,    92,   116,   149,   159,   701,   723,   150,
     297,   143,    26,    34,   150,   835,   162,    31,    32,   701,
     152,   116,   619,   164,   619,   116,   795,   314,   164,   911,
     163,   399,   399,   134,    48,    49,    50,   931,   325,    31,
      32,   409,   409,    57,    34,   146,   158,   153,   160,   417,
     417,   155,   155,   399,   120,   148,   153,   559,   148,   148,
     148,   489,    92,   409,   151,    57,   795,   148,   153,   148,
     148,   417,   669,   163,    33,    89,   163,   153,   960,   153,
     148,    95,   153,   148,   148,   148,   130,   153,   148,   148,
     210,   219,   136,   795,   795,   159,   148,   148,   218,   153,
     148,   795,   470,   470,   701,    11,   701,   148,   148,   148,
     148,   148,    33,   795,    33,    34,    35,   151,   250,   149,
     958,   959,   948,   949,   376,    31,    32,   129,   120,    74,
     164,     4,   134,   953,   421,   422,   138,   148,    11,   153,
     151,    26,   510,   510,    33,    34,    31,    32,   986,    77,
     578,   579,    33,   913,   980,   981,   163,   983,    31,    32,
      16,    17,    18,    48,    49,    50,    29,   313,    72,    73,
      74,   133,    57,    77,   934,    31,    32,   139,   140,   141,
     972,    30,   942,    32,   104,   104,   978,   555,   555,    64,
      65,    66,   444,   445,   446,   447,   448,   134,   795,   451,
     795,   134,   135,   455,    89,   134,   155,   156,   157,   158,
      95,   160,   134,   162,    31,    32,    33,   149,   150,   587,
     587,   148,   149,   150,    33,   134,   131,   132,   912,   134,
     652,   653,   654,   601,   601,   149,   150,   142,   143,   144,
     145,   146,   147,   156,   157,   158,   159,   160,   161,   730,
      34,   619,   619,   152,    63,   158,    33,   160,    35,   149,
     150,   159,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   647,
     647,    90,    91,   149,   150,    94,   573,   574,   575,   576,
     577,   149,   150,   580,   103,   152,   583,   149,   150,   134,
     386,   669,   669,   686,   149,   150,   392,   427,   149,   150,
     149,   150,   149,   150,   104,   124,   149,   150,   404,   427,
     149,   150,   427,   149,   150,   152,   412,   149,   150,   149,
     150,   113,   114,   701,   701,   149,   150,   149,   150,   459,
     134,   149,   150,   149,   150,   149,   150,   149,   150,   763,
     764,   968,   969,   473,   134,   701,    92,   858,   859,    74,
     152,   152,   134,   148,   134,   701,   134,    62,   151,    33,
     151,    33,   151,   151,    93,   461,   151,   151,   464,   165,
     151,    33,   151,   156,   149,   151,   916,   148,   151,   156,
     151,   151,   151,   708,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   536,   166,   552,   168,   169,   837,
     151,   151,   840,   151,   151,   158,   151,   151,   705,   151,
     151,   507,   151,   151,    33,   152,   151,   795,   795,   151,
     151,   151,   104,   151,   151,   151,   149,   167,   152,   559,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   795,
     148,   559,    94,   836,   559,    35,    35,    33,    33,   795,
     712,   713,    33,   104,   596,   597,   598,   151,    34,   152,
      34,   104,    35,    35,    33,   148,   152,   154,    33,   154,
     148,    35,   614,   615,   616,   617,    35,    35,    35,   148,
     150,   149,    33,   154,   151,   149,   152,   137,   618,   128,
     151,   151,    94,   148,   150,   154,   154,   154,    16,   152,
     149,   149,   149,   117,    17,   151,   151,   151,   664,    33,
     148,   165,    33,   153,   149,   149,   954,   814,   815,    35,
      35,   818,   900,   900,   154,   154,   668,   154,   154,   154,
     148,   151,   154,    18,   831,   156,   148,   148,    69,   162,
     682,   979,    63,   148,   900,   923,   923,   162,   165,   150,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   923,   104,    90,
      91,   701,   165,   870,   730,    33,    33,   148,   708,   166,
      33,   165,   103,   880,   152,   165,   149,   149,   154,    33,
     151,   151,   730,   148,   736,   151,   148,    47,    11,   149,
     154,   154,   148,   124,    36,   747,   748,   154,   750,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   760,   761,
     154,   166,    46,   149,   154,   154,   148,   154,   167,   149,
      31,    32,    33,     1,   167,   357,   669,   594,   935,   619,
     437,   351,   354,   463,   443,   466,   406,   433,   409,   360,
     414,   417,   647,   950,   363,   696,    57,   699,   430,     3,
     816,    62,    63,   399,   367,   795,   963,   642,   217,   293,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   394,    89,    90,
      91,   833,   380,    94,   383,   639,   919,   923,   862,   508,
     582,   795,   103,   861,   601,   106,   107,   197,   296,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,    -1,
      -1,    -1,   123,   124,    -1,    -1,    -1,    -1,   858,   859,
     860,   861,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   860,    -1,    -1,    -1,    -1,    -1,    -1,   905,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    26,    -1,    -1,    -1,   928,    31,
      32,    33,   944,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,   956,    -1,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,   966,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,
     122,    -1,   124,    -1,     3,   127,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    -1,    23,    24,    25,    -1,    27,    28,
      29,   153,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    90,    91,    -1,    -1,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   103,    -1,    -1,   106,   107,   108,
     109,   110,   111,    -1,    -1,    -1,    -1,   116,    10,    11,
     119,    -1,    -1,    -1,   123,   124,   125,   126,    -1,    -1,
      22,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    -1,    94,    95,    -1,    31,    32,    33,    -1,    -1,
      -1,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,
     122,    57,   124,    -1,    -1,   127,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    33,    89,    90,    91,    -1,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    63,   119,    -1,    -1,    -1,   123,   124,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    -1,    90,
      91,    -1,    33,    94,    35,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,    -1,    63,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    33,    -1,    90,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,   104,   105,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,   124,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    33,    90,    91,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    63,    -1,    -1,    -1,    -1,   124,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    33,
      90,    91,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    63,
      -1,    -1,    -1,    -1,   124,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    -1,    90,    91,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   171,   172,   173,     0,   172,     3,     5,     6,     7,
       8,     9,    10,    12,    13,    14,    15,    19,    20,    21,
      23,    24,    25,    27,    28,    29,    31,    32,    33,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    89,    90,
      91,    94,   103,   106,   107,   108,   109,   110,   111,   116,
     119,   123,   124,   125,   126,   174,   175,   176,   180,   184,
     188,   192,   196,   202,   204,   210,   214,   218,   222,   226,
     229,   230,   234,   238,   242,   249,   256,   266,   270,   271,
     278,   279,   280,   281,   293,   295,   296,   297,   298,   299,
     300,   301,   302,   304,   305,   315,   319,   322,   337,   338,
     342,   343,   346,   348,   349,   377,   399,   403,   407,    33,
     148,   193,    35,   148,   177,    35,   148,   181,    33,   148,
     185,    33,   148,   189,    30,   320,   321,   320,   320,   320,
      33,   148,   316,    34,   320,   320,   320,   320,   320,   320,
     320,   320,    63,   407,   148,    34,   148,   267,    34,    34,
     148,   272,   320,   320,   320,    33,    34,   148,   257,   264,
     264,   148,   243,   264,   148,   250,   264,   337,   337,    74,
      33,   325,    77,    72,    73,    74,    77,   407,   403,    33,
     223,   215,    33,   148,   219,    35,   148,   231,   403,   337,
     163,   148,   235,   264,   148,   239,   264,    92,   163,    29,
     347,    33,   116,   406,   104,   134,   146,   194,   195,   134,
     178,   179,   134,   182,   183,   134,   186,   187,   134,   190,
     191,   320,    30,    32,   130,   136,   317,   318,   320,    34,
     324,   337,   159,   381,    33,   155,   227,   228,   325,   134,
     135,   268,   269,   134,   273,   274,   131,   132,   134,   142,
     143,   144,   145,   146,   147,   259,   260,   152,   261,   258,
     104,   265,   134,   244,   245,   152,   246,   134,   251,   252,
     152,   253,   350,   344,   381,    74,   406,    33,   148,   211,
     152,   152,   134,   220,   221,   133,   139,   140,   141,   232,
     233,   381,   148,   148,   197,   403,   408,   134,   236,   237,
     134,   240,   241,   338,   408,   407,   349,   148,   381,   148,
     151,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   166,   168,   169,   378,   158,   160,   405,   151,   151,
     149,   150,   151,   149,   150,   151,   149,   150,   151,   149,
     150,   151,   149,   150,   151,   151,   149,   150,   320,    33,
     382,   383,   203,    33,    93,   149,   156,   151,   151,   149,
     150,   151,   149,   150,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   149,   150,     4,    11,   226,   229,   262,
     263,   306,   310,   265,   151,   149,   150,   226,   229,   247,
     248,   310,   151,   149,   150,   226,   229,   254,   255,   310,
     165,   352,   352,   323,   405,   381,   158,   152,   212,    33,
     224,   225,    33,   216,   217,   151,   149,   150,   151,   151,
     151,   151,   149,   150,    96,    97,    98,    99,   100,   101,
     102,   118,   388,   389,   390,   403,   404,   337,   381,   150,
     164,   151,   149,   150,   151,   149,   150,   164,   381,   388,
     152,   400,   149,   148,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   163,   151,   164,   167,   151,   151,   148,
      94,    33,    35,   366,   104,   195,    35,   179,    35,   183,
      33,   187,    33,   191,    33,   104,   318,   151,   150,   159,
     152,   206,    33,   155,   325,    34,   113,   114,   339,   269,
      34,   274,    35,    35,   264,   339,   339,   339,    33,   104,
     264,   260,   148,   307,    35,   148,   311,   153,   263,   264,
     245,   153,   248,   264,   252,   153,   255,    64,    65,    66,
     353,   354,   355,   381,   381,   152,   154,    33,   175,   213,
     348,   154,   153,   225,   153,   217,   366,   221,    35,    35,
      35,    35,   233,   325,   325,   325,   325,   325,   148,   148,
     325,   149,   150,   325,   151,   331,   149,   152,   198,   403,
     264,   237,   264,   241,   205,   149,    16,    17,    18,   226,
     229,   401,   402,   154,   403,   151,   151,   388,    33,    35,
     104,   264,   384,   383,    26,    48,    49,    50,    95,   207,
     208,   209,   226,   229,   281,   290,   294,   322,    33,   137,
     308,   309,   128,   312,   313,   320,   154,   154,   154,   150,
     337,   351,   345,    33,   226,   229,   326,   327,   328,   149,
     153,   175,   381,   381,   381,   381,   381,   388,   388,   381,
      94,   379,   390,   381,   148,   332,   335,   336,   120,   199,
     200,   201,   226,   229,   281,   206,   379,   320,   320,   320,
     153,   402,    16,   275,   149,   149,   165,   320,   320,   320,
     320,   403,   153,   208,   151,   149,   150,   151,   149,   150,
     354,   152,   356,   356,   151,   330,   153,   328,   148,   331,
     331,   331,   149,   149,   117,   409,   337,   156,   157,   158,
     159,   160,   161,   333,   155,   156,   157,   158,   160,   162,
     334,   320,   153,   200,   409,   320,    17,   276,   154,   379,
     265,    33,   154,    35,   309,    35,   313,    10,    22,    33,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    49,
      50,    51,    64,    65,    66,    67,    68,    70,    88,    95,
     122,   127,   196,   210,   226,   229,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   294,   303,
     310,   322,   342,   343,   349,   357,   358,   359,   368,   369,
     371,   376,   377,   391,   394,   396,   397,   399,   154,   154,
     335,   381,   154,   408,   325,   325,   148,   151,   380,   149,
     335,    35,   104,   105,   112,   115,   337,   339,   340,   407,
     154,   380,   320,    18,   277,   409,   156,   148,   320,   320,
     148,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,    69,   367,   367,   367,   165,   392,   393,
     398,   395,   370,   148,   360,   153,   358,   162,   150,   329,
     149,   381,   381,   337,   410,   104,   381,   148,   381,   320,
     380,   265,   388,   388,   165,   165,   165,    88,   394,   394,
     377,   403,   396,    33,   371,   129,   134,   138,   361,   362,
     152,   363,    33,   381,   149,   150,   166,   374,   332,   341,
     374,   381,   149,   149,    33,   151,   151,   151,   149,   150,
     226,   229,   310,   364,   365,   148,   154,   337,   375,   154,
     149,   150,   154,   374,   379,   409,    33,   366,    33,   362,
     153,   365,   149,   403,    47,   386,   332,   310,   314,   154,
     409,   381,   154,   409,   148,   320,    36,   387,   386,   386,
     381,   166,   372,   380,   388,   320,    46,   385,   387,   387,
     374,   373,   154,   381,   149,   320,   385,   385,   154,   148,
     314,   154,   167,   314,   388,   386,   386,   386,   149,   387,
     167
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1806 of yacc.c  */
#line 551 "parser.y"
    {
            /*
             * We don't do these in parserEOF() because the parser is reading
             * ahead and that would be too early.
             */

            if (previousFile != NULL)
            {
                handleEOF();

                if (currentContext.prevmod != NULL)
                    handleEOM();

                free(previousFile);
                previousFile = NULL;
            }
    }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 619 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope == NULL)
                    yyerror("%TypeHeaderCode can only be used in a namespace, class or mapped type");

                appendCodeBlock(&scope->iff->hdrcode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 632 "parser.y"
    {
            if (notSkipping())
                currentModule->defdocstring = convertFormat((yyvsp[(2) - (2)].defdocstring).name);
        }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 638 "parser.y"
    {
            resetLexerState();

            (yyval.defdocstring).name = (yyvsp[(1) - (1)].text);
        }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 643 "parser.y"
    {
            (yyval.defdocstring) = (yyvsp[(2) - (3)].defdocstring);
        }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 649 "parser.y"
    {
            (yyval.defdocstring) = (yyvsp[(1) - (3)].defdocstring);

            switch ((yyvsp[(3) - (3)].defdocstring).token)
            {
            case TK_NAME: (yyval.defdocstring).name = (yyvsp[(3) - (3)].defdocstring).name; break;
            }
        }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 659 "parser.y"
    {
            (yyval.defdocstring).token = TK_NAME;

            (yyval.defdocstring).name = (yyvsp[(3) - (3)].text);
        }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 666 "parser.y"
    {
            if (notSkipping())
            {
                if ((currentModule->encoding = convertEncoding((yyvsp[(2) - (2)].defencoding).name)) == no_type)
                    yyerror("The %DefaultEncoding name must be one of \"ASCII\", \"Latin-1\", \"UTF-8\" or \"None\"");
            }
        }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 675 "parser.y"
    {
            resetLexerState();

            (yyval.defencoding).name = (yyvsp[(1) - (1)].text);
        }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 680 "parser.y"
    {
            (yyval.defencoding) = (yyvsp[(2) - (3)].defencoding);
        }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 686 "parser.y"
    {
            (yyval.defencoding) = (yyvsp[(1) - (3)].defencoding);

            switch ((yyvsp[(3) - (3)].defencoding).token)
            {
            case TK_NAME: (yyval.defencoding).name = (yyvsp[(3) - (3)].defencoding).name; break;
            }
        }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 696 "parser.y"
    {
            (yyval.defencoding).token = TK_NAME;

            (yyval.defencoding).name = (yyvsp[(3) - (3)].text);
        }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 703 "parser.y"
    {
            /* Note that %Plugin is internal in SIP v4. */

            if (notSkipping())
                appendString(&currentSpec->plugins, (yyvsp[(2) - (2)].plugin).name);
        }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 711 "parser.y"
    {
            resetLexerState();

            (yyval.plugin).name = (yyvsp[(1) - (1)].text);
        }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 716 "parser.y"
    {
            (yyval.plugin) = (yyvsp[(2) - (3)].plugin);
        }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 722 "parser.y"
    {
            (yyval.plugin) = (yyvsp[(1) - (3)].plugin);

            switch ((yyvsp[(3) - (3)].plugin).token)
            {
            case TK_NAME: (yyval.plugin).name = (yyvsp[(3) - (3)].plugin).name; break;
            }
        }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 732 "parser.y"
    {
            (yyval.plugin).token = TK_NAME;

            (yyval.plugin).name = (yyvsp[(3) - (3)].text);
        }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 739 "parser.y"
    {
            if ((yyvsp[(2) - (3)].veh).name == NULL)
                yyerror("%VirtualErrorHandler must have a 'name' argument");

            if (notSkipping())
            {
                virtErrorHandler *veh, **tailp;

                /* Check there isn't already a handler with the same name. */
                for (tailp = &currentSpec->errorhandlers; (veh = *tailp) != NULL; tailp = &veh->next)
                    if (strcmp(veh->name, (yyvsp[(2) - (3)].veh).name) == 0)
                        break;

                if (veh != NULL)
                    yyerror("A virtual error handler with that name has already been defined");

                veh = sipMalloc(sizeof (virtErrorHandler));

                veh->name = (yyvsp[(2) - (3)].veh).name;
                appendCodeBlock(&veh->code, (yyvsp[(3) - (3)].codeb));
                veh->mod = currentModule;
                veh->index = currentModule->nrvirterrorhandlers++;
                veh->next = NULL;

                *tailp = veh;
            }
        }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 768 "parser.y"
    {
            resetLexerState();

            (yyval.veh).name = (yyvsp[(1) - (1)].text);
        }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 773 "parser.y"
    {
            (yyval.veh) = (yyvsp[(2) - (3)].veh);
        }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 779 "parser.y"
    {
            (yyval.veh) = (yyvsp[(1) - (3)].veh);

            switch ((yyvsp[(3) - (3)].veh).token)
            {
            case TK_NAME: (yyval.veh).name = (yyvsp[(3) - (3)].veh).name; break;
            }
        }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 789 "parser.y"
    {
            (yyval.veh).token = TK_NAME;

            (yyval.veh).name = (yyvsp[(3) - (3)].text);
        }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 796 "parser.y"
    {
            if (notSkipping())
            {
                apiVersionRangeDef *avd;

                if (findAPI(currentSpec, (yyvsp[(2) - (2)].api).name) != NULL)
                    yyerror("The API name in the %API directive has already been defined");

                if ((yyvsp[(2) - (2)].api).version < 1)
                    yyerror("The version number in the %API directive must be greater than or equal to 1");

                avd = sipMalloc(sizeof (apiVersionRangeDef));

                avd->api_name = cacheName(currentSpec, (yyvsp[(2) - (2)].api).name);
                avd->from = (yyvsp[(2) - (2)].api).version;
                avd->to = -1;

                avd->next = currentModule->api_versions;
                currentModule->api_versions = avd;

                if (inMainModule())
                    setIsUsedName(avd->api_name);
            }
        }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 822 "parser.y"
    {
            resetLexerState();

            deprecated("%API name and version number should be specified using the 'name' and 'version' arguments");

            (yyval.api).name = (yyvsp[(1) - (2)].text);
            (yyval.api).version = (yyvsp[(2) - (2)].number);
        }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 830 "parser.y"
    {
            (yyval.api) = (yyvsp[(2) - (3)].api);
        }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 836 "parser.y"
    {
            (yyval.api) = (yyvsp[(1) - (3)].api);

            switch ((yyvsp[(3) - (3)].api).token)
            {
            case TK_NAME: (yyval.api).name = (yyvsp[(3) - (3)].api).name; break;
            case TK_VERSION: (yyval.api).version = (yyvsp[(3) - (3)].api).version; break;
            }
        }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 847 "parser.y"
    {
            (yyval.api).token = TK_NAME;

            (yyval.api).name = (yyvsp[(3) - (3)].text);
            (yyval.api).version = 0;
        }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 853 "parser.y"
    {
            (yyval.api).token = TK_VERSION;

            (yyval.api).name = NULL;
            (yyval.api).version = (yyvsp[(3) - (3)].number);
        }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 861 "parser.y"
    {
            if (notSkipping())
            {
                static const char *annos[] = {
                    "Default",
                    "PyName",
                    NULL
                };

                exceptionDef *xd;
                const char *pyname;

                checkAnnos(&(yyvsp[(4) - (5)].optflags), annos);

                if (currentSpec->genc)
                    yyerror("%Exception not allowed in a C module");

                if ((yyvsp[(5) - (5)].exception).raise_code == NULL)
                    yyerror("%Exception must have a %RaiseCode sub-directive");

                pyname = getPythonName(currentModule, &(yyvsp[(4) - (5)].optflags), scopedNameTail((yyvsp[(2) - (5)].scpvalp)));

                checkAttributes(currentSpec, currentModule, NULL, NULL,
                        pyname, FALSE);

                xd = findException(currentSpec, (yyvsp[(2) - (5)].scpvalp), TRUE);

                if (xd->cd != NULL)
                    yyerror("%Exception name has already been seen as a class name - it must be defined before being used");

                if (xd->iff->module != NULL)
                    yyerror("The %Exception has already been defined");

                /* Complete the definition. */
                xd->iff->module = currentModule;
                appendCodeBlock(&xd->iff->hdrcode, (yyvsp[(5) - (5)].exception).type_header_code);
                xd->pyname = pyname;
                xd->bibase = (yyvsp[(3) - (5)].exceptionbase).bibase;
                xd->base = (yyvsp[(3) - (5)].exceptionbase).base;
                appendCodeBlock(&xd->raisecode, (yyvsp[(5) - (5)].exception).raise_code);

                if (getOptFlag(&(yyvsp[(4) - (5)].optflags), "Default", bool_flag) != NULL)
                    currentModule->defexception = xd;

                if (xd->bibase != NULL || xd->base != NULL)
                    xd->exceptionnr = currentModule->nrexceptions++;
            }
        }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 911 "parser.y"
    {
            (yyval.exceptionbase).bibase = NULL;
            (yyval.exceptionbase).base = NULL;
        }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 915 "parser.y"
    {
            exceptionDef *xd;

            (yyval.exceptionbase).bibase = NULL;
            (yyval.exceptionbase).base = NULL;

            /* See if it is a defined exception. */
            for (xd = currentSpec->exceptions; xd != NULL; xd = xd->next)
                if (compareScopedNames(xd->iff->fqcname, (yyvsp[(2) - (3)].scpvalp)) == 0)
                {
                    (yyval.exceptionbase).base = xd;
                    break;
                }

            if (xd == NULL && (yyvsp[(2) - (3)].scpvalp)->next == NULL && strncmp((yyvsp[(2) - (3)].scpvalp)->name, "SIP_", 4) == 0)
            {
                /* See if it is a builtin exception. */

                static char *builtins[] = {
                    "BaseException",
                    "Exception",
                    "StopIteration",
                    "GeneratorExit",
                    "ArithmeticError",
                    "LookupError",
                    "StandardError",                /* Python v2. */

                    "AssertionError",
                    "AttributeError",
                    "BufferError",
                    "EOFError",
                    "FloatingPointError",
                    "OSError",
                    "ImportError",
                    "IndexError",
                    "KeyError",
                    "KeyboardInterrupt",
                    "MemoryError",
                    "NameError",
                    "OverflowError",
                    "RuntimeError",
                    "NotImplementedError",
                    "SyntaxError",
                    "IndentationError",
                    "TabError",
                    "ReferenceError",
                    "SystemError",
                    "SystemExit",
                    "TypeError",
                    "UnboundLocalError",
                    "UnicodeError",
                    "UnicodeEncodeError",
                    "UnicodeDecodeError",
                    "UnicodeTranslateError",
                    "ValueError",
                    "ZeroDivisionError",
                    "EnvironmentError",             /* Python v2. */
                    "IOError",                      /* Python v2. */
                    "WindowsError",                 /* Python v2. */
                    "VMSError",                     /* Python v2. */

                    "BlockingIOError",
                    "BrokenPipeError",
                    "ChildProcessError",
                    "ConnectionError",
                    "ConnectionAbortedError",
                    "ConnectionRefusedError",
                    "ConnectionResetError",
                    "FileExistsError",
                    "FileNotFoundError",
                    "InterruptedError",
                    "IsADirectoryError",
                    "NotADirectoryError",
                    "PermissionError",
                    "ProcessLookupError",
                    "TimeoutError",

                    "Warning",
                    "UserWarning",
                    "DeprecationWarning",
                    "PendingDeprecationWarning",
                    "SyntaxWarning",
                    "RuntimeWarning",
                    "FutureWarning",
                    "ImportWarning",
                    "UnicodeWarning",
                    "BytesWarning",
                    "ResourceWarning",

                    NULL
                };

                char **cp;

                for (cp = builtins; *cp != NULL; ++cp)
                    if (strcmp((yyvsp[(2) - (3)].scpvalp)->name + 4, *cp) == 0)
                    {
                        (yyval.exceptionbase).bibase = *cp;
                        break;
                    }
            }

            if ((yyval.exceptionbase).bibase == NULL && (yyval.exceptionbase).base == NULL)
                yyerror("Unknown exception base type");
        }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1022 "parser.y"
    {
            (yyval.exception) = (yyvsp[(2) - (4)].exception);
        }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1028 "parser.y"
    {
            (yyval.exception) = (yyvsp[(1) - (2)].exception);

            switch ((yyvsp[(2) - (2)].exception).token)
            {
            case TK_RAISECODE: (yyval.exception).raise_code = (yyvsp[(2) - (2)].exception).raise_code; break;
            case TK_TYPEHEADERCODE: (yyval.exception).type_header_code = (yyvsp[(2) - (2)].exception).type_header_code; break;
            }
        }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1039 "parser.y"
    {
            (yyval.exception).token = TK_IF;
        }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1042 "parser.y"
    {
            (yyval.exception).token = TK_END;
        }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1045 "parser.y"
    {
            if (notSkipping())
            {
                (yyval.exception).token = TK_RAISECODE;
                (yyval.exception).raise_code = (yyvsp[(1) - (1)].codeb);
            }
            else
            {
                (yyval.exception).token = 0;
                (yyval.exception).raise_code = NULL;
            }

            (yyval.exception).type_header_code = NULL;
        }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1059 "parser.y"
    {
            if (notSkipping())
            {
                (yyval.exception).token = TK_TYPEHEADERCODE;
                (yyval.exception).type_header_code = (yyvsp[(1) - (1)].codeb);
            }
            else
            {
                (yyval.exception).token = 0;
                (yyval.exception).type_header_code = NULL;
            }

            (yyval.exception).raise_code = NULL;
        }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1075 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1080 "parser.y"
    {
            if (notSkipping())
            {
                static const char *annos[] = {
                    "AllowNone",
                    "API",
                    "DocType",
                    "NoRelease",
                    "PyName",
                    "TypeHint",
                    "TypeHintIn",
                    "TypeHintOut",
                    "TypeHintValue",
                    NULL
                };

                checkAnnos(&(yyvsp[(3) - (3)].optflags), annos);

                currentMappedType = newMappedType(currentSpec, &(yyvsp[(2) - (3)].memArg), &(yyvsp[(3) - (3)].optflags));
            }
        }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1103 "parser.y"
    {
            if (notSkipping())
            {
                static const char *annos[] = {
                    "AllowNone",
                    "DocType",
                    "NoRelease",
                    "TypeHint",
                    "TypeHintIn",
                    "TypeHintOut",
                    "TypeHintValue",
                    NULL
                };

                int a;
                mappedTypeTmplDef *mtt;
                ifaceFileDef *iff;

                checkAnnos(&(yyvsp[(4) - (4)].optflags), annos);

                if (currentSpec->genc)
                    yyerror("%MappedType templates not allowed in a C module");

                /*
                 * Check the template arguments are basic types or simple
                 * names.
                 */
                for (a = 0; a < (yyvsp[(1) - (4)].signature).nrArgs; ++a)
                {
                    argDef *ad = &(yyvsp[(1) - (4)].signature).args[a];

                    if (ad->atype == defined_type && ad->u.snd->next != NULL)
                        yyerror("%MappedType template arguments must be simple names");
                }

                if ((yyvsp[(3) - (4)].memArg).atype != template_type)
                    yyerror("%MappedType template must map a template type");

                /* Check a template hasn't already been provided. */
                for (mtt = currentSpec->mappedtypetemplates; mtt != NULL; mtt = mtt->next)
                    if (compareScopedNames(mtt->mt->type.u.td->fqname, (yyvsp[(3) - (4)].memArg).u.td->fqname) == 0 && sameTemplateSignature(&mtt->mt->type.u.td->types, &(yyvsp[(3) - (4)].memArg).u.td->types, TRUE))
                        yyerror("%MappedType template for this type has already been defined");

                (yyvsp[(3) - (4)].memArg).nrderefs = 0;
                (yyvsp[(3) - (4)].memArg).argflags = 0;

                mtt = sipMalloc(sizeof (mappedTypeTmplDef));

                mtt->sig = (yyvsp[(1) - (4)].signature);
                mtt->mt = allocMappedType(currentSpec, &(yyvsp[(3) - (4)].memArg));
                mappedTypeAnnos(mtt->mt, &(yyvsp[(4) - (4)].optflags));
                mtt->next = currentSpec->mappedtypetemplates;

                currentSpec->mappedtypetemplates = mtt;

                currentMappedType = mtt->mt;

                /* Create a dummy interface file. */
                iff = sipMalloc(sizeof (ifaceFileDef));
                iff->hdrcode = NULL;
                mtt->mt->iff = iff;
            }
        }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1168 "parser.y"
    {
            if (notSkipping())
            {
                if (currentMappedType->convfromcode == NULL)
                    yyerror("%MappedType must have a %ConvertFromTypeCode directive");

                if (currentMappedType->convtocode == NULL)
                    yyerror("%MappedType must have a %ConvertToTypeCode directive");

                currentMappedType = NULL;
            }
        }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 1188 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentMappedType->iff->hdrcode, (yyvsp[(1) - (1)].codeb));
        }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 1192 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentMappedType->typecode, (yyvsp[(1) - (1)].codeb));
        }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 1196 "parser.y"
    {
            if (notSkipping())
            {
                if (currentMappedType->convfromcode != NULL)
                    yyerror("%MappedType has more than one %ConvertFromTypeCode directive");

                appendCodeBlock(&currentMappedType->convfromcode, (yyvsp[(2) - (2)].codeb));
            }
        }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 1205 "parser.y"
    {
            if (notSkipping())
            {
                if (currentMappedType->convtocode != NULL)
                    yyerror("%MappedType has more than one %ConvertToTypeCode directive");

                appendCodeBlock(&currentMappedType->convtocode, (yyvsp[(2) - (2)].codeb));
            }
        }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 1214 "parser.y"
    {
            if (notSkipping())
            {
                if (currentMappedType->instancecode != NULL)
                    yyerror("%MappedType has more than one %InstanceCode directive");

                appendCodeBlock(&currentMappedType->instancecode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 1227 "parser.y"
    {
            if (notSkipping())
            {
                applyTypeFlags(currentModule, &(yyvsp[(2) - (13)].memArg), &(yyvsp[(9) - (13)].optflags));

                (yyvsp[(5) - (13)].signature).result = (yyvsp[(2) - (13)].memArg);

                newFunction(currentSpec, currentModule, NULL,
                        currentMappedType, 0, TRUE, FALSE, FALSE, FALSE, (yyvsp[(3) - (13)].text),
                        &(yyvsp[(5) - (13)].signature), (yyvsp[(7) - (13)].number), FALSE, &(yyvsp[(9) - (13)].optflags), (yyvsp[(13) - (13)].codeb), NULL, NULL, (yyvsp[(8) - (13)].throwlist), (yyvsp[(10) - (13)].optsignature), (yyvsp[(12) - (13)].codeb));
            }
        }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 1241 "parser.y"
    {
            if (currentSpec -> genc)
                yyerror("namespace definition not allowed in a C module");

            if (notSkipping())
            {
                classDef *ns, *c_scope;
                ifaceFileDef *scope;

                if ((c_scope = currentScope()) != NULL)
                    scope = c_scope->iff;
                else
                    scope = NULL;

                ns = newClass(currentSpec, namespace_iface, NULL,
                        text2scopedName(scope, (yyvsp[(2) - (2)].text)), NULL, NULL, NULL, NULL);

                pushScope(ns);

                sectionFlags = 0;
            }
        }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 1262 "parser.y"
    {
            if (notSkipping())
            {
                if (inMainModule())
                {
                    classDef *ns = currentScope();

                    setIsUsedName(ns->iff->name);
                    setIsUsedName(ns->pyname);
                }

                popScope();
            }
        }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 1286 "parser.y"
    {
            if (notSkipping())
            {
                qualDef *qd;

                for (qd = currentModule->qualifiers; qd != NULL; qd = qd->next)
                    if (qd->qtype == platform_qualifier)
                        yyerror("%Platforms has already been defined for this module");
            }
        }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 1296 "parser.y"
    {
            if (notSkipping())
            {
                qualDef *qd;
                int nrneeded;

                /* Check that exactly one platform in the set was requested. */
                nrneeded = 0;

                for (qd = currentModule->qualifiers; qd != NULL; qd = qd->next)
                    if (qd->qtype == platform_qualifier && selectedQualifier(neededQualifiers, qd))
                        ++nrneeded;

                if (nrneeded > 1)
                    yyerror("No more than one of these %Platforms must be specified with the -t flag");
            }
        }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1319 "parser.y"
    {
            newQualifier(currentModule, -1, -1, notSkipping(), (yyvsp[(1) - (1)].text),
                    platform_qualifier);
        }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1325 "parser.y"
    {
            newQualifier(currentModule, -1, -1, notSkipping(), (yyvsp[(2) - (2)].feature).name,
                    feature_qualifier);
        }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 1331 "parser.y"
    {
            resetLexerState();

            (yyval.feature).name = (yyvsp[(1) - (1)].text);
        }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 1336 "parser.y"
    {
            (yyval.feature) = (yyvsp[(2) - (3)].feature);
        }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 1342 "parser.y"
    {
            (yyval.feature) = (yyvsp[(1) - (3)].feature);

            switch ((yyvsp[(3) - (3)].feature).token)
            {
            case TK_NAME: (yyval.feature).name = (yyvsp[(3) - (3)].feature).name; break;
            }
        }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 1352 "parser.y"
    {
            (yyval.feature).token = TK_NAME;

            (yyval.feature).name = (yyvsp[(3) - (3)].text);
        }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 1359 "parser.y"
    {
            currentTimelineOrder = 0;
        }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 1362 "parser.y"
    {
            if (notSkipping())
            {
                qualDef *qd;
                int nrneeded;

                /*
                 * Check that exactly one time slot in the set was requested.
                 */
                nrneeded = 0;

                for (qd = currentModule->qualifiers; qd != NULL; qd = qd->next)
                    if (qd->qtype == time_qualifier && selectedQualifier(neededQualifiers, qd))
                        ++nrneeded;

                if (nrneeded > 1)
                    yyerror("At most one of this %Timeline must be specified with the -t flag");

                currentModule->nrtimelines++;
            }
        }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 1389 "parser.y"
    {
            newQualifier(currentModule, currentModule->nrtimelines,
                    currentTimelineOrder++, TRUE, (yyvsp[(1) - (1)].text), time_qualifier);
        }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 1395 "parser.y"
    {
            if (skipStackPtr >= MAX_NESTED_IF)
                yyerror("Internal error: increase the value of MAX_NESTED_IF");

            /* Nested %Ifs are implicit logical ands. */

            if (skipStackPtr > 0)
                (yyvsp[(3) - (4)].boolean) = ((yyvsp[(3) - (4)].boolean) && skipStack[skipStackPtr - 1]);

            skipStack[skipStackPtr++] = (yyvsp[(3) - (4)].boolean);
        }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 1408 "parser.y"
    {
            (yyval.boolean) = platOrFeature((yyvsp[(1) - (1)].text),FALSE);
        }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 1411 "parser.y"
    {
            (yyval.boolean) = platOrFeature((yyvsp[(2) - (2)].text),TRUE);
        }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 1414 "parser.y"
    {
            (yyval.boolean) = (platOrFeature((yyvsp[(3) - (3)].text),FALSE) || (yyvsp[(1) - (3)].boolean));
        }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 1417 "parser.y"
    {
            (yyval.boolean) = (platOrFeature((yyvsp[(4) - (4)].text),TRUE) || (yyvsp[(1) - (4)].boolean));
        }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 1423 "parser.y"
    {
            (yyval.boolean) = timePeriod((yyvsp[(1) - (3)].text), (yyvsp[(3) - (3)].text));
        }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 1428 "parser.y"
    {
            if (skipStackPtr-- <= 0)
                yyerror("Too many %End directives");
        }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 1434 "parser.y"
    {
            optFlag *of;

            if ((yyvsp[(3) - (3)].optflags).nrFlags != 0)
                deprecated("%License annotations are deprecated, use arguments instead");

            if ((yyvsp[(2) - (3)].license).type == NULL)
                if ((of = getOptFlag(&(yyvsp[(3) - (3)].optflags), "Type", string_flag)) != NULL)
                    (yyvsp[(2) - (3)].license).type = of->fvalue.sval;

            if ((yyvsp[(2) - (3)].license).licensee == NULL)
                if ((of = getOptFlag(&(yyvsp[(3) - (3)].optflags), "Licensee", string_flag)) != NULL)
                    (yyvsp[(2) - (3)].license).licensee = of->fvalue.sval;

            if ((yyvsp[(2) - (3)].license).signature == NULL)
                if ((of = getOptFlag(&(yyvsp[(3) - (3)].optflags), "Signature", string_flag)) != NULL)
                    (yyvsp[(2) - (3)].license).signature = of->fvalue.sval;

            if ((yyvsp[(2) - (3)].license).timestamp == NULL)
                if ((of = getOptFlag(&(yyvsp[(3) - (3)].optflags), "Timestamp", string_flag)) != NULL)
                    (yyvsp[(2) - (3)].license).timestamp = of->fvalue.sval;

            if ((yyvsp[(2) - (3)].license).type == NULL)
                yyerror("%License must have a 'type' argument");

            if (notSkipping())
            {
                currentModule->license = sipMalloc(sizeof (licenseDef));

                currentModule->license->type = (yyvsp[(2) - (3)].license).type;
                currentModule->license->licensee = (yyvsp[(2) - (3)].license).licensee;
                currentModule->license->sig = (yyvsp[(2) - (3)].license).signature;
                currentModule->license->timestamp = (yyvsp[(2) - (3)].license).timestamp;
            }
        }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 1471 "parser.y"
    {
            resetLexerState();

            (yyval.license).type = NULL;
            (yyval.license).licensee = NULL;
            (yyval.license).signature = NULL;
            (yyval.license).timestamp = NULL;
        }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 1479 "parser.y"
    {
            (yyval.license).type = (yyvsp[(1) - (1)].text);
            (yyval.license).licensee = NULL;
            (yyval.license).signature = NULL;
            (yyval.license).timestamp = NULL;
        }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1485 "parser.y"
    {
            (yyval.license) = (yyvsp[(2) - (3)].license);
        }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1491 "parser.y"
    {
            (yyval.license) = (yyvsp[(1) - (3)].license);

            switch ((yyvsp[(3) - (3)].license).token)
            {
            case TK_TYPE: (yyval.license).type = (yyvsp[(3) - (3)].license).type; break;
            case TK_LICENSEE: (yyval.license).licensee = (yyvsp[(3) - (3)].license).licensee; break;
            case TK_SIGNATURE: (yyval.license).signature = (yyvsp[(3) - (3)].license).signature; break;
            case TK_TIMESTAMP: (yyval.license).timestamp = (yyvsp[(3) - (3)].license).timestamp; break;
            }
        }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1504 "parser.y"
    {
            (yyval.license).token = TK_NAME;

            (yyval.license).type = (yyvsp[(3) - (3)].text);
            (yyval.license).licensee = NULL;
            (yyval.license).signature = NULL;
            (yyval.license).timestamp = NULL;
        }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1512 "parser.y"
    {
            (yyval.license).token = TK_LICENSEE;

            (yyval.license).type = NULL;
            (yyval.license).licensee = (yyvsp[(3) - (3)].text);
            (yyval.license).signature = NULL;
            (yyval.license).timestamp = NULL;
        }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1520 "parser.y"
    {
            (yyval.license).token = TK_SIGNATURE;

            (yyval.license).type = NULL;
            (yyval.license).licensee = NULL;
            (yyval.license).signature = (yyvsp[(3) - (3)].text);
            (yyval.license).timestamp = NULL;
        }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1528 "parser.y"
    {
            (yyval.license).token = TK_TIMESTAMP;

            (yyval.license).type = NULL;
            (yyval.license).licensee = NULL;
            (yyval.license).signature = NULL;
            (yyval.license).timestamp = (yyvsp[(3) - (3)].text);
        }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1538 "parser.y"
    {
            if (notSkipping())
            {
                if (currentModule->defmetatype != NULL)
                    yyerror("%DefaultMetatype has already been defined for this module");

                currentModule->defmetatype = cacheName(currentSpec, (yyvsp[(2) - (2)].defmetatype).name);
            }
        }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1549 "parser.y"
    {
            resetLexerState();

            (yyval.defmetatype).name = (yyvsp[(1) - (1)].text);
        }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1554 "parser.y"
    {
            (yyval.defmetatype) = (yyvsp[(2) - (3)].defmetatype);
        }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1560 "parser.y"
    {
            (yyval.defmetatype) = (yyvsp[(1) - (3)].defmetatype);

            switch ((yyvsp[(3) - (3)].defmetatype).token)
            {
            case TK_NAME: (yyval.defmetatype).name = (yyvsp[(3) - (3)].defmetatype).name; break;
            }
        }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1570 "parser.y"
    {
            (yyval.defmetatype).token = TK_NAME;

            (yyval.defmetatype).name = (yyvsp[(3) - (3)].text);
        }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1577 "parser.y"
    {
            if (notSkipping())
            {
                if (currentModule->defsupertype != NULL)
                    yyerror("%DefaultSupertype has already been defined for this module");

                currentModule->defsupertype = cacheName(currentSpec, (yyvsp[(2) - (2)].defsupertype).name);
            }
        }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1588 "parser.y"
    {
            resetLexerState();

            (yyval.defsupertype).name = (yyvsp[(1) - (1)].text);
        }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1593 "parser.y"
    {
            (yyval.defsupertype) = (yyvsp[(2) - (3)].defsupertype);
        }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1599 "parser.y"
    {
            (yyval.defsupertype) = (yyvsp[(1) - (3)].defsupertype);

            switch ((yyvsp[(3) - (3)].defsupertype).token)
            {
            case TK_NAME: (yyval.defsupertype).name = (yyvsp[(3) - (3)].defsupertype).name; break;
            }
        }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1609 "parser.y"
    {
            (yyval.defsupertype).token = TK_NAME;

            (yyval.defsupertype).name = (yyvsp[(3) - (3)].text);
        }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1616 "parser.y"
    {
            deprecated("%ConsolidatedModule is deprecated and will not be supported by SIP v5");

            if (notSkipping())
            {
                /* Make sure this is the first mention of a module. */
                if (currentSpec->module != currentModule)
                    yyerror("A %ConsolidatedModule cannot be %Imported");

                if (currentModule->fullname != NULL)
                    yyerror("%ConsolidatedModule must appear before any %Module or %CModule directive");

                setModuleName(currentSpec, currentModule, (yyvsp[(2) - (3)].consmodule).name);
                appendCodeBlock(&currentModule->docstring, (yyvsp[(3) - (3)].consmodule).docstring);

                setIsConsolidated(currentModule);
            }
        }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1636 "parser.y"
    {
            resetLexerState();

            (yyval.consmodule).name = (yyvsp[(1) - (1)].text);
        }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1641 "parser.y"
    {
            (yyval.consmodule) = (yyvsp[(2) - (3)].consmodule);
        }
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1647 "parser.y"
    {
            (yyval.consmodule) = (yyvsp[(1) - (3)].consmodule);

            switch ((yyvsp[(3) - (3)].consmodule).token)
            {
            case TK_NAME: (yyval.consmodule).name = (yyvsp[(3) - (3)].consmodule).name; break;
            }
        }
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1657 "parser.y"
    {
            (yyval.consmodule).token = TK_NAME;

            (yyval.consmodule).name = (yyvsp[(3) - (3)].text);
        }
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1664 "parser.y"
    {
            (yyval.consmodule).token = 0;
            (yyval.consmodule).docstring = NULL;
        }
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 1668 "parser.y"
    {
            (yyval.consmodule) = (yyvsp[(2) - (4)].consmodule);
        }
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 1674 "parser.y"
    {
            (yyval.consmodule) = (yyvsp[(1) - (2)].consmodule);

            switch ((yyvsp[(2) - (2)].consmodule).token)
            {
            case TK_DOCSTRING: (yyval.consmodule).docstring = (yyvsp[(2) - (2)].consmodule).docstring; break;
            }
        }
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1684 "parser.y"
    {
            (yyval.consmodule).token = TK_IF;
        }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1687 "parser.y"
    {
            (yyval.consmodule).token = TK_END;
        }
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1690 "parser.y"
    {
            if (notSkipping())
            {
                (yyval.consmodule).token = TK_DOCSTRING;
                (yyval.consmodule).docstring = (yyvsp[(1) - (1)].codeb);
            }
            else
            {
                (yyval.consmodule).token = 0;
                (yyval.consmodule).docstring = NULL;
            }
        }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1704 "parser.y"
    {
            if (notSkipping())
            {
                /* Make sure this is the first mention of a module. */
                if (currentSpec->module != currentModule)
                    yyerror("A %CompositeModule cannot be %Imported");

                if (currentModule->fullname != NULL)
                    yyerror("%CompositeModule must appear before any %Module directive");

                setModuleName(currentSpec, currentModule, (yyvsp[(2) - (3)].compmodule).name);
                appendCodeBlock(&currentModule->docstring, (yyvsp[(3) - (3)].compmodule).docstring);

                setIsComposite(currentModule);
            }
        }
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1722 "parser.y"
    {
            resetLexerState();

            (yyval.compmodule).name = (yyvsp[(1) - (1)].text);
        }
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1727 "parser.y"
    {
            (yyval.compmodule) = (yyvsp[(2) - (3)].compmodule);
        }
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1733 "parser.y"
    {
            (yyval.compmodule) = (yyvsp[(1) - (3)].compmodule);

            switch ((yyvsp[(3) - (3)].compmodule).token)
            {
            case TK_NAME: (yyval.compmodule).name = (yyvsp[(3) - (3)].compmodule).name; break;
            }
        }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1743 "parser.y"
    {
            (yyval.compmodule).token = TK_NAME;

            (yyval.compmodule).name = (yyvsp[(3) - (3)].text);
        }
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1750 "parser.y"
    {
            (yyval.compmodule).token = 0;
            (yyval.compmodule).docstring = NULL;
        }
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1754 "parser.y"
    {
            (yyval.compmodule) = (yyvsp[(2) - (4)].compmodule);
        }
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1760 "parser.y"
    {
            (yyval.compmodule) = (yyvsp[(1) - (2)].compmodule);

            switch ((yyvsp[(2) - (2)].compmodule).token)
            {
            case TK_DOCSTRING: (yyval.compmodule).docstring = (yyvsp[(2) - (2)].compmodule).docstring; break;
            }
        }
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1770 "parser.y"
    {
            (yyval.compmodule).token = TK_IF;
        }
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1773 "parser.y"
    {
            (yyval.compmodule).token = TK_END;
        }
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 1776 "parser.y"
    {
            if (notSkipping())
            {
                (yyval.compmodule).token = TK_DOCSTRING;
                (yyval.compmodule).docstring = (yyvsp[(1) - (1)].codeb);
            }
            else
            {
                (yyval.compmodule).token = 0;
                (yyval.compmodule).docstring = NULL;
            }
        }
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 1790 "parser.y"
    {
            if ((yyvsp[(2) - (3)].module).name == NULL)
                yyerror("%Module must have a 'name' argument");

            if (notSkipping())
                currentModule = configureModule(currentSpec, currentModule,
                        currentContext.filename, (yyvsp[(2) - (3)].module).name, (yyvsp[(2) - (3)].module).version,
                        (yyvsp[(2) - (3)].module).c_module, (yyvsp[(2) - (3)].module).kwargs, (yyvsp[(2) - (3)].module).use_arg_names,
                        (yyvsp[(2) - (3)].module).call_super_init, (yyvsp[(2) - (3)].module).all_raise_py_exc,
                        (yyvsp[(2) - (3)].module).def_error_handler, (yyvsp[(3) - (3)].module).docstring, (yyvsp[(2) - (3)].module).nameshort);
        }
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 1801 "parser.y"
    {
            deprecated("%CModule is deprecated, use %Module and the 'language' argument instead");

            if (notSkipping())
                currentModule = configureModule(currentSpec, currentModule,
                        currentContext.filename, (yyvsp[(2) - (3)].text), (yyvsp[(3) - (3)].number), TRUE, defaultKwArgs,
                        FALSE, -1, FALSE, NULL, NULL, NULL);
        }
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 1811 "parser.y"
    {resetLexerState();}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 1811 "parser.y"
    {
            if ((yyvsp[(3) - (3)].number) >= 0)
                deprecated("%Module version number should be specified using the 'version' argument");

            (yyval.module).c_module = FALSE;
            (yyval.module).kwargs = defaultKwArgs;
            (yyval.module).name = (yyvsp[(1) - (3)].text);
            (yyval.module).nameshort = NULL;
            (yyval.module).use_arg_names = FALSE;
            (yyval.module).all_raise_py_exc = FALSE;
            (yyval.module).call_super_init = -1;
            (yyval.module).def_error_handler = NULL;
            (yyval.module).version = (yyvsp[(3) - (3)].number);
        }
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 1825 "parser.y"
    {
            (yyval.module) = (yyvsp[(2) - (3)].module);
        }
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 1831 "parser.y"
    {
            (yyval.module) = (yyvsp[(1) - (3)].module);

            switch ((yyvsp[(3) - (3)].module).token)
            {
            case TK_KWARGS: (yyval.module).kwargs = (yyvsp[(3) - (3)].module).kwargs; break;
            case TK_LANGUAGE: (yyval.module).c_module = (yyvsp[(3) - (3)].module).c_module; break;
            case TK_NAME: (yyval.module).name = (yyvsp[(3) - (3)].module).name; break;
            case TK_NAMESHORT: (yyval.module).nameshort = (yyvsp[(3) - (3)].module).nameshort; break;
            case TK_USEARGNAMES: (yyval.module).use_arg_names = (yyvsp[(3) - (3)].module).use_arg_names; break;
            case TK_ALLRAISEPYEXC: (yyval.module).all_raise_py_exc = (yyvsp[(3) - (3)].module).all_raise_py_exc; break;
            case TK_CALLSUPERINIT: (yyval.module).call_super_init = (yyvsp[(3) - (3)].module).call_super_init; break;
            case TK_DEFERRORHANDLER: (yyval.module).def_error_handler = (yyvsp[(3) - (3)].module).def_error_handler; break;
            case TK_VERSION: (yyval.module).version = (yyvsp[(3) - (3)].module).version; break;
            }
        }
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 1849 "parser.y"
    {
            (yyval.module).token = TK_KWARGS;

            (yyval.module).c_module = FALSE;
            (yyval.module).kwargs = convertKwArgs((yyvsp[(3) - (3)].text));
            (yyval.module).name = NULL;
            (yyval.module).nameshort = NULL;
            (yyval.module).use_arg_names = FALSE;
            (yyval.module).all_raise_py_exc = FALSE;
            (yyval.module).call_super_init = -1;
            (yyval.module).def_error_handler = NULL;
            (yyval.module).version = -1;
        }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 1862 "parser.y"
    {
            (yyval.module).token = TK_LANGUAGE;

            if (strcmp((yyvsp[(3) - (3)].text), "C++") == 0)
                (yyval.module).c_module = FALSE;
            else if (strcmp((yyvsp[(3) - (3)].text), "C") == 0)
                (yyval.module).c_module = TRUE;
            else
                yyerror("%Module 'language' argument must be either \"C++\" or \"C\"");

            (yyval.module).kwargs = defaultKwArgs;
            (yyval.module).name = NULL;
            (yyval.module).nameshort = NULL;
            (yyval.module).use_arg_names = FALSE;
            (yyval.module).all_raise_py_exc = FALSE;
            (yyval.module).call_super_init = -1;
            (yyval.module).def_error_handler = NULL;
            (yyval.module).version = -1;
        }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 1881 "parser.y"
    {
            (yyval.module).token = TK_NAME;

            (yyval.module).c_module = FALSE;
            (yyval.module).kwargs = defaultKwArgs;
            (yyval.module).name = (yyvsp[(3) - (3)].text);
            (yyval.module).nameshort = NULL;
            (yyval.module).use_arg_names = FALSE;
            (yyval.module).all_raise_py_exc = FALSE;
            (yyval.module).call_super_init = -1;
            (yyval.module).def_error_handler = NULL;
            (yyval.module).version = -1;
        }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 1894 "parser.y"
    {
            (yyval.module).token = TK_NAMESHORT;

            (yyval.module).c_module = FALSE;
            (yyval.module).kwargs = defaultKwArgs;
            (yyval.module).name = NULL;
            (yyval.module).nameshort = (yyvsp[(3) - (3)].text);
            (yyval.module).use_arg_names = FALSE;
            (yyval.module).all_raise_py_exc = FALSE;
            (yyval.module).call_super_init = -1;
            (yyval.module).def_error_handler = NULL;
            (yyval.module).version = -1;
        }
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 1907 "parser.y"
    {
            (yyval.module).token = TK_USEARGNAMES;

            (yyval.module).c_module = FALSE;
            (yyval.module).kwargs = defaultKwArgs;
            (yyval.module).name = NULL;
            (yyval.module).nameshort = NULL;
            (yyval.module).use_arg_names = (yyvsp[(3) - (3)].boolean);
            (yyval.module).all_raise_py_exc = FALSE;
            (yyval.module).call_super_init = -1;
            (yyval.module).def_error_handler = NULL;
            (yyval.module).version = -1;
        }
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 1920 "parser.y"
    {
            (yyval.module).token = TK_ALLRAISEPYEXC;

            (yyval.module).c_module = FALSE;
            (yyval.module).kwargs = defaultKwArgs;
            (yyval.module).name = NULL;
            (yyval.module).nameshort = NULL;
            (yyval.module).use_arg_names = FALSE;
            (yyval.module).all_raise_py_exc = (yyvsp[(3) - (3)].boolean);
            (yyval.module).call_super_init = -1;
            (yyval.module).def_error_handler = NULL;
            (yyval.module).version = -1;
        }
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 1933 "parser.y"
    {
            (yyval.module).token = TK_CALLSUPERINIT;

            (yyval.module).c_module = FALSE;
            (yyval.module).kwargs = defaultKwArgs;
            (yyval.module).name = NULL;
            (yyval.module).nameshort = NULL;
            (yyval.module).use_arg_names = FALSE;
            (yyval.module).all_raise_py_exc = FALSE;
            (yyval.module).call_super_init = (yyvsp[(3) - (3)].boolean);
            (yyval.module).def_error_handler = NULL;
            (yyval.module).version = -1;
        }
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 1946 "parser.y"
    {
            (yyval.module).token = TK_DEFERRORHANDLER;

            (yyval.module).c_module = FALSE;
            (yyval.module).kwargs = defaultKwArgs;
            (yyval.module).name = NULL;
            (yyval.module).nameshort = NULL;
            (yyval.module).use_arg_names = FALSE;
            (yyval.module).all_raise_py_exc = FALSE;
            (yyval.module).call_super_init = -1;
            (yyval.module).def_error_handler = (yyvsp[(3) - (3)].text);
            (yyval.module).version = -1;
        }
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 1959 "parser.y"
    {
            if ((yyvsp[(3) - (3)].number) < 0)
                yyerror("%Module 'version' argument cannot be negative");

            (yyval.module).token = TK_VERSION;

            (yyval.module).c_module = FALSE;
            (yyval.module).kwargs = defaultKwArgs;
            (yyval.module).name = NULL;
            (yyval.module).nameshort = NULL;
            (yyval.module).use_arg_names = FALSE;
            (yyval.module).all_raise_py_exc = FALSE;
            (yyval.module).call_super_init = -1;
            (yyval.module).def_error_handler = NULL;
            (yyval.module).version = (yyvsp[(3) - (3)].number);
        }
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 1977 "parser.y"
    {
            (yyval.module).token = 0;
            (yyval.module).docstring = NULL;
        }
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 1981 "parser.y"
    {
            (yyval.module) = (yyvsp[(2) - (4)].module);
        }
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 1987 "parser.y"
    {
            (yyval.module) = (yyvsp[(1) - (2)].module);

            switch ((yyvsp[(2) - (2)].module).token)
            {
            case TK_DOCSTRING: (yyval.module).docstring = (yyvsp[(2) - (2)].module).docstring; break;
            }
        }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 1997 "parser.y"
    {
            (yyval.module).token = TK_IF;
        }
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 2000 "parser.y"
    {
            (yyval.module).token = TK_END;
        }
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 2003 "parser.y"
    {
            (yyval.module).token = TK_AUTOPYNAME;
        }
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 2006 "parser.y"
    {
            if (notSkipping())
            {
                (yyval.module).token = TK_DOCSTRING;
                (yyval.module).docstring = (yyvsp[(1) - (1)].codeb);
            }
            else
            {
                (yyval.module).token = 0;
                (yyval.module).docstring = NULL;
            }
        }
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 2021 "parser.y"
    {
            /*
             * The grammar design is a bit broken and this is the easiest way
             * to allow periods in names.
             */

            char *cp;

            for (cp = (yyvsp[(1) - (1)].text); *cp != '\0'; ++cp)
                if (*cp != '.' && *cp != '_' && !isalnum(*cp))
                    yyerror("Invalid character in name");

            (yyval.text) = (yyvsp[(1) - (1)].text);
        }
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 2037 "parser.y"
    {
            (yyval.number) = -1;
        }
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 2043 "parser.y"
    {
            if ((yyvsp[(2) - (2)].include).name == NULL)
                yyerror("%Include must have a 'name' argument");

            if (notSkipping())
                parseFile(NULL, (yyvsp[(2) - (2)].include).name, NULL, (yyvsp[(2) - (2)].include).optional);
        }
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 2052 "parser.y"
    {
            resetLexerState();

            (yyval.include).name = (yyvsp[(1) - (1)].text);
            (yyval.include).optional = FALSE;
        }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 2058 "parser.y"
    {
            (yyval.include) = (yyvsp[(2) - (3)].include);
        }
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 2064 "parser.y"
    {
            (yyval.include) = (yyvsp[(1) - (3)].include);

            switch ((yyvsp[(3) - (3)].include).token)
            {
            case TK_NAME: (yyval.include).name = (yyvsp[(3) - (3)].include).name; break;
            case TK_OPTIONAL: (yyval.include).optional = (yyvsp[(3) - (3)].include).optional; break;
            }
        }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 2075 "parser.y"
    {
            (yyval.include).token = TK_NAME;

            (yyval.include).name = (yyvsp[(3) - (3)].text);
            (yyval.include).optional = FALSE;
        }
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 2081 "parser.y"
    {
            (yyval.include).token = TK_OPTIONAL;

            (yyval.include).name = NULL;
            (yyval.include).optional = (yyvsp[(3) - (3)].boolean);
        }
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 2089 "parser.y"
    {
            deprecated("%OptionalInclude is deprecated, use %Include and the 'optional' argument instead");

            if (notSkipping())
                parseFile(NULL, (yyvsp[(2) - (2)].text), NULL, TRUE);
        }
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 2097 "parser.y"
    {
            if (notSkipping())
                newImport((yyvsp[(2) - (2)].import).name);
        }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 2103 "parser.y"
    {
            resetLexerState();

            (yyval.import).name = (yyvsp[(1) - (1)].text);
        }
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 2108 "parser.y"
    {
            (yyval.import) = (yyvsp[(2) - (3)].import);
        }
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 2114 "parser.y"
    {
            (yyval.import) = (yyvsp[(1) - (3)].import);

            switch ((yyvsp[(3) - (3)].import).token)
            {
            case TK_NAME: (yyval.import).name = (yyvsp[(3) - (3)].import).name; break;
            }
        }
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 2124 "parser.y"
    {
            (yyval.import).token = TK_NAME;

            (yyval.import).name = (yyvsp[(3) - (3)].text);
        }
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 2131 "parser.y"
    {
            (yyval.codeb) = NULL;
        }
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 2134 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 2139 "parser.y"
    {
            (yyval.codeb) = NULL;
        }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 2142 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 2147 "parser.y"
    {
            (yyval.codeb) = NULL;
        }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 2150 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 2155 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentModule->copying, (yyvsp[(2) - (2)].codeb));
        }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 2161 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentSpec->exphdrcode, (yyvsp[(2) - (2)].codeb));
        }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 2167 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentModule->hdrcode, (yyvsp[(2) - (2)].codeb));
        }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 2173 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 2178 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 2183 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 2188 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 2193 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 2198 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 2203 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 2208 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 2213 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 2218 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 2223 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 2228 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 2233 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentModule->cppcode, (yyvsp[(2) - (2)].codeb));
        }
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 2239 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 2244 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentModule->preinitcode, (yyvsp[(2) - (2)].codeb));
        }
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 2250 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentModule->initcode, (yyvsp[(2) - (2)].codeb));
        }
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 2256 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentModule->postinitcode, (yyvsp[(2) - (2)].codeb));
        }
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 2262 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentModule->unitcode, (yyvsp[(2) - (2)].codeb));
        }
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 2268 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentModule->unitpostinccode, (yyvsp[(2) - (2)].codeb));
        }
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 2274 "parser.y"
    {
            /* Deprecated. */
        }
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 2279 "parser.y"
    {
            if (notSkipping() && !inMainModule())
                appendCodeBlock(&currentSpec->exptypehintcode, (yyvsp[(2) - (2)].codeb));
        }
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 2285 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentModule->typehintcode, (yyvsp[(2) - (2)].codeb));
        }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 2291 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 2296 "parser.y"
    {
            if (notSkipping() && inMainModule())
                appendCodeBlock(&currentSpec->docs, (yyvsp[(2) - (2)].codeb));
        }
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 2302 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentSpec->docs, (yyvsp[(2) - (2)].codeb));
        }
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 2308 "parser.y"
    {
            if (notSkipping())
                addAutoPyName(currentModule, (yyvsp[(2) - (2)].autopyname).remove_leading);
        }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 2314 "parser.y"
    {
            (yyval.autopyname) = (yyvsp[(2) - (3)].autopyname);
        }
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 2320 "parser.y"
    {
            (yyval.autopyname) = (yyvsp[(1) - (3)].autopyname);

            switch ((yyvsp[(3) - (3)].autopyname).token)
            {
            case TK_REMOVELEADING: (yyval.autopyname).remove_leading = (yyvsp[(3) - (3)].autopyname).remove_leading; break;
            }
        }
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 2330 "parser.y"
    {
            (yyval.autopyname).token = TK_REMOVELEADING;

            (yyval.autopyname).remove_leading = (yyvsp[(3) - (3)].text);
        }
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 2337 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(3) - (3)].codeb);

            /* Format the docstring. */
            if ((yyvsp[(2) - (3)].docstring).format == deindented)
            {
                const char *cp;
                char *dp;
                int min_indent, indent, skipping;

                /* Find the common indent. */
                min_indent = -1;
                indent = 0;
                skipping = FALSE;

                for (cp = (yyval.codeb)->frag; *cp != '\0'; ++cp)
                {
                    if (skipping)
                    {
                        /*
                         * We have handled the indent and are just looking for
                         * the end of the line.
                         */
                        if (*cp == '\n')
                            skipping = FALSE;
                    }
                    else
                    {
                        if (*cp == ' ')
                        {
                            ++indent;
                        }
                        else if (*cp != '\n')
                        {
                            if (min_indent < 0 || min_indent > indent)
                                min_indent = indent;

                            /* Ignore the remaining characters of the line. */
                            skipping = TRUE;
                        }
                    }
                }

                /* In case the last line doesn't have a trailing newline. */
                if (min_indent < 0 || min_indent > indent)
                    min_indent = indent;

                /*
                 * Go through the text again removing the common indentation.
                 */
                cp = dp = (yyval.codeb)->frag;

                while (*cp != '\0')
                {
                    const char *start = cp;
                    int non_blank = FALSE;

                    /* Find the end of the line. */
                    while (*cp != '\n' && *cp != '\0')
                        if (*cp++ != ' ')
                            non_blank = TRUE;

                    /* Find where we are copying from. */
                    if (non_blank)
                    {
                        start += min_indent;

                        while (*start != '\n' && *start != '\0')
                            *dp++ = *start++;
                    }

                    if (*cp == '\n')
                        *dp++ = *cp++;
                }

                *dp = '\0';
            }
        }
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 2417 "parser.y"
    {
            (yyval.docstring).format = currentModule->defdocstring;
        }
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 2420 "parser.y"
    {
            resetLexerState();

            (yyval.docstring).format = convertFormat((yyvsp[(1) - (1)].text));
        }
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 2425 "parser.y"
    {
            (yyval.docstring) = (yyvsp[(2) - (3)].docstring);
        }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 2431 "parser.y"
    {
            (yyval.docstring) = (yyvsp[(1) - (3)].docstring);

            switch ((yyvsp[(3) - (3)].docstring).token)
            {
            case TK_FORMAT: (yyval.docstring).format = (yyvsp[(3) - (3)].docstring).format; break;
            }
        }
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 2441 "parser.y"
    {
            (yyval.docstring).token = TK_FORMAT;

            (yyval.docstring).format = convertFormat((yyvsp[(3) - (3)].text));
        }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 2448 "parser.y"
    {
            (yyval.codeb) = NULL;
        }
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 2454 "parser.y"
    {
            if ((yyvsp[(2) - (3)].extract).id == NULL)
                yyerror("%Extract must have an 'id' argument");

            if (notSkipping())
                addExtractPart(currentSpec, (yyvsp[(2) - (3)].extract).id, (yyvsp[(2) - (3)].extract).order, (yyvsp[(3) - (3)].codeb));
        }
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 2463 "parser.y"
    {
            resetLexerState();

            (yyval.extract).id = (yyvsp[(1) - (1)].text);
            (yyval.extract).order = -1;
        }
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 2469 "parser.y"
    {
            (yyval.extract) = (yyvsp[(2) - (3)].extract);
        }
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 2475 "parser.y"
    {
            (yyval.extract) = (yyvsp[(1) - (3)].extract);

            switch ((yyvsp[(3) - (3)].extract).token)
            {
            case TK_ID: (yyval.extract).id = (yyvsp[(3) - (3)].extract).id; break;
            case TK_ORDER: (yyval.extract).order = (yyvsp[(3) - (3)].extract).order; break;
            }
        }
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 2486 "parser.y"
    {
            (yyval.extract).token = TK_ID;

            (yyval.extract).id = (yyvsp[(3) - (3)].text);
            (yyval.extract).order = -1;
        }
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 2492 "parser.y"
    {
            (yyval.extract).token = TK_ORDER;

            if ((yyvsp[(3) - (3)].number) < 0)
                yyerror("The 'order' of an %Extract directive must not be negative");

            (yyval.extract).id = NULL;
            (yyval.extract).order = (yyvsp[(3) - (3)].number);
        }
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 2503 "parser.y"
    {
            /* Deprecated. */
        }
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 2512 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(1) - (2)].codeb);

            append(&(yyval.codeb)->frag, (yyvsp[(2) - (2)].codeb)->frag);

            free((yyvsp[(2) - (2)].codeb)->frag);
            free((yyvsp[(2) - (2)].codeb));
        }
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 2522 "parser.y"
    {
            if (notSkipping())
            {
                const char *annos[] = {
                    "NoScope",
                    "NoTypeHint",
                    "PyName",
                    NULL
                };

                checkAnnos(&(yyvsp[(3) - (3)].optflags), annos);

                if (sectionFlags != 0 && (sectionFlags & ~(SECT_IS_PUBLIC | SECT_IS_PROT)) != 0)
                    yyerror("Class enums must be in the public or protected sections");

                currentEnum = newEnum(currentSpec, currentModule,
                        currentMappedType, (yyvsp[(2) - (3)].text), &(yyvsp[(3) - (3)].optflags), sectionFlags);
            }
        }
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 2543 "parser.y"
    {
            (yyval.text) = NULL;
        }
    break;

  case 295:

/* Line 1806 of yacc.c  */
#line 2546 "parser.y"
    {
            (yyval.text) = (yyvsp[(1) - (1)].text);
        }
    break;

  case 296:

/* Line 1806 of yacc.c  */
#line 2551 "parser.y"
    {
            (yyval.text) = NULL;
        }
    break;

  case 297:

/* Line 1806 of yacc.c  */
#line 2554 "parser.y"
    {
            (yyval.text) = (yyvsp[(1) - (1)].text);
        }
    break;

  case 304:

/* Line 1806 of yacc.c  */
#line 2569 "parser.y"
    {
            if (notSkipping())
            {
                const char *annos[] = {
                    "NoTypeHint",
                    "PyName",
                    NULL
                };

                enumMemberDef *emd, **tail;

                checkAnnos(&(yyvsp[(3) - (4)].optflags), annos);

                /* Note that we don't use the assigned value. */
                emd = sipMalloc(sizeof (enumMemberDef));

                emd->pyname = cacheName(currentSpec,
                        getPythonName(currentModule, &(yyvsp[(3) - (4)].optflags), (yyvsp[(1) - (4)].text)));
                emd->cname = (yyvsp[(1) - (4)].text);
                emd->no_typehint = getNoTypeHint(&(yyvsp[(3) - (4)].optflags));
                emd->ed = currentEnum;
                emd->next = NULL;

                checkAttributes(currentSpec, currentModule, emd->ed->ecd,
                        emd->ed->emtd, emd->pyname->text, FALSE);

                /* Append to preserve the order. */
                for (tail = &currentEnum->members; *tail != NULL; tail = &(*tail)->next)
                    ;

                *tail = emd;

                if (inMainModule())
                    setIsUsedName(emd->pyname);
            }
        }
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 2615 "parser.y"
    {
            (yyval.valp) = NULL;
        }
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 2618 "parser.y"
    {
            (yyval.valp) = (yyvsp[(2) - (2)].valp);
        }
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 2624 "parser.y"
    {
            valueDef *vd;
 
            if ((yyvsp[(1) - (3)].valp) -> vtype == string_value || (yyvsp[(3) - (3)].valp) -> vtype == string_value)
                yyerror("Invalid binary operator for string");
 
            /* Find the last value in the existing expression. */
 
            for (vd = (yyvsp[(1) - (3)].valp); vd -> next != NULL; vd = vd -> next)
                ;
 
            vd -> vbinop = (yyvsp[(2) - (3)].qchar);
            vd -> next = (yyvsp[(3) - (3)].valp);

            (yyval.valp) = (yyvsp[(1) - (3)].valp);
        }
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 2642 "parser.y"
    {
            (yyval.qchar) = '-';
        }
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 2645 "parser.y"
    {
            (yyval.qchar) = '+';
        }
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 2648 "parser.y"
    {
            (yyval.qchar) = '*';
        }
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 2651 "parser.y"
    {
            (yyval.qchar) = '/';
        }
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 2654 "parser.y"
    {
            (yyval.qchar) = '&';
        }
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 2657 "parser.y"
    {
            (yyval.qchar) = '|';
        }
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 2662 "parser.y"
    {
            (yyval.qchar) = '\0';
        }
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 2665 "parser.y"
    {
            (yyval.qchar) = '!';
        }
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 2668 "parser.y"
    {
            (yyval.qchar) = '~';
        }
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 2671 "parser.y"
    {
            (yyval.qchar) = '-';
        }
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 2674 "parser.y"
    {
            (yyval.qchar) = '+';
        }
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 2677 "parser.y"
    {
            (yyval.qchar) = '*';
        }
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 2680 "parser.y"
    {
            (yyval.qchar) = '&';
        }
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 2685 "parser.y"
    {
            if ((yyvsp[(2) - (3)].qchar) != '\0' && (yyvsp[(3) - (3)].value).vtype == string_value)
                yyerror("Invalid unary operator for string");
 
            /* Convert the value to a simple expression on the heap. */
            (yyval.valp) = sipMalloc(sizeof (valueDef));
 
            *(yyval.valp) = (yyvsp[(3) - (3)].value);
            (yyval.valp)->vunop = (yyvsp[(2) - (3)].qchar);
            (yyval.valp)->vbinop = '\0';
            (yyval.valp)->cast = (yyvsp[(1) - (3)].scpvalp);
            (yyval.valp)->next = NULL;
        }
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 2700 "parser.y"
    {
            (yyval.scpvalp) = NULL;
        }
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 2703 "parser.y"
    {
            (yyval.scpvalp) = (yyvsp[(2) - (3)].scpvalp);
        }
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 2709 "parser.y"
    {
            if (currentSpec -> genc)
                yyerror("Scoped names are not allowed in a C module");

            appendScopedName(&(yyvsp[(1) - (3)].scpvalp),(yyvsp[(3) - (3)].scpvalp));
        }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 2717 "parser.y"
    {
            (yyval.scpvalp) = text2scopePart((yyvsp[(1) - (1)].text));
        }
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 2722 "parser.y"
    {
            (yyval.boolean) = TRUE;
        }
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 2725 "parser.y"
    {
            (yyval.boolean) = FALSE;
        }
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 2730 "parser.y"
    {
            /*
             * We let the C++ compiler decide if the value is a valid one - no
             * point in building a full C++ parser here.
             */

            (yyval.value).vtype = scoped_value;
            (yyval.value).u.vscp = (yyvsp[(1) - (1)].scpvalp);
        }
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 2739 "parser.y"
    {
            fcallDef *fcd;

            fcd = sipMalloc(sizeof (fcallDef));
            *fcd = (yyvsp[(3) - (4)].fcall);
            fcd -> type = (yyvsp[(1) - (4)].memArg);

            (yyval.value).vtype = fcall_value;
            (yyval.value).u.fcd = fcd;
        }
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 2749 "parser.y"
    {
            (yyval.value).vtype = real_value;
            (yyval.value).u.vreal = (yyvsp[(1) - (1)].real);
        }
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 2753 "parser.y"
    {
            (yyval.value).vtype = numeric_value;
            (yyval.value).u.vnum = (yyvsp[(1) - (1)].number);
        }
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 2757 "parser.y"
    {
            (yyval.value).vtype = numeric_value;
            (yyval.value).u.vnum = (yyvsp[(1) - (1)].boolean);
        }
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2761 "parser.y"
    {
            (yyval.value).vtype = numeric_value;
            (yyval.value).u.vnum = 0;
        }
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2765 "parser.y"
    {
            (yyval.value).vtype = string_value;
            (yyval.value).u.vstr = (yyvsp[(1) - (1)].text);
        }
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 2769 "parser.y"
    {
            (yyval.value).vtype = qchar_value;
            (yyval.value).u.vqchar = (yyvsp[(1) - (1)].qchar);
        }
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 2775 "parser.y"
    {
            /* No values. */

            (yyval.fcall).nrArgs = 0;
        }
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 2780 "parser.y"
    {
            /* The single or first expression. */

            (yyval.fcall).args[0] = (yyvsp[(1) - (1)].valp);
            (yyval.fcall).nrArgs = 1;
        }
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 2786 "parser.y"
    {
            /* Check that it wasn't ...(,expression...). */

            if ((yyval.fcall).nrArgs == 0)
                yyerror("First argument to function call is missing");

            /* Check there is room. */

            if ((yyvsp[(1) - (3)].fcall).nrArgs == MAX_NR_ARGS)
                yyerror("Internal error - increase the value of MAX_NR_ARGS");

            (yyval.fcall) = (yyvsp[(1) - (3)].fcall);

            (yyval.fcall).args[(yyval.fcall).nrArgs] = (yyvsp[(3) - (3)].valp);
            (yyval.fcall).nrArgs++;
        }
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 2804 "parser.y"
    {
            if (notSkipping())
            {
                const char *annos[] = {
                    "Capsule",
                    "DocType",
                    "Encoding",
                    "NoTypeName",
                    "PyInt",
                    "PyName",
                    "TypeHint",
                    "TypeHintIn",
                    "TypeHintOut",
                    NULL
                };

                checkAnnos(&(yyvsp[(4) - (5)].optflags), annos);

                applyTypeFlags(currentModule, &(yyvsp[(2) - (5)].memArg), &(yyvsp[(4) - (5)].optflags));
                newTypedef(currentSpec, currentModule, (yyvsp[(3) - (5)].text), &(yyvsp[(2) - (5)].memArg), &(yyvsp[(4) - (5)].optflags));
            }
        }
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 2826 "parser.y"
    {
            if (notSkipping())
            {
                const char *annos[] = {
                    "DocType",
                    "Encoding",
                    "NoTypeName",
                    "PyInt",
                    "PyName",
                    "TypeHint",
                    "TypeHintIn",
                    "TypeHintOut",
                    NULL
                };

                signatureDef *sig;
                argDef ftype;

                checkAnnos(&(yyvsp[(10) - (11)].optflags), annos);

                applyTypeFlags(currentModule, &(yyvsp[(2) - (11)].memArg), &(yyvsp[(10) - (11)].optflags));

                memset(&ftype, 0, sizeof (argDef));

                /* Create the full signature on the heap. */
                sig = sipMalloc(sizeof (signatureDef));
                *sig = (yyvsp[(8) - (11)].signature);
                sig->result = (yyvsp[(2) - (11)].memArg);

                /* Create the full type. */
                ftype.atype = function_type;
                ftype.nrderefs = 1;
                ftype.u.sa = sig;

                newTypedef(currentSpec, currentModule, (yyvsp[(5) - (11)].text), &ftype, &(yyvsp[(10) - (11)].optflags));
            }
        }
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 2865 "parser.y"
    {
            if (currentSpec -> genc && (yyvsp[(2) - (2)].scpvalp)->next != NULL)
                yyerror("Namespaces not allowed in a C module");

            if (notSkipping())
                currentSupers = NULL;
        }
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 2871 "parser.y"
    {
            if (notSkipping())
            {
                const char *annos[] = {
                    "Abstract",
                    "AllowNone",
                    "API",
                    "DelayDtor",
                    "Deprecated",
                    "ExportDerived",
                    "External",
                    "FileExtension",
                    "Metatype",
                    "Mixin",
                    "NoDefaultCtors",
                    "NoTypeHint",
                    "PyName",
                    "PyQtFlags",
                    "PyQtInterface",
                    "PyQtNoQMetaObject",
                    "Supertype",
                    "TypeHint",
                    "TypeHintIn",
                    "TypeHintOut",
                    "TypeHintValue",
                    "VirtualErrorHandler",
                    NULL
                };

                checkAnnos(&(yyvsp[(5) - (5)].optflags), annos);

                if (currentSpec->genc && currentSupers != NULL)
                    yyerror("Super-classes not allowed in a C module struct");

                defineClass((yyvsp[(2) - (5)].scpvalp), currentSupers, &(yyvsp[(5) - (5)].optflags));
                sectionFlags = SECT_IS_PUBLIC;
            }
        }
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 2908 "parser.y"
    {
            if (notSkipping())
                completeClass((yyvsp[(2) - (8)].scpvalp), &(yyvsp[(5) - (8)].optflags), (yyvsp[(7) - (8)].boolean));
        }
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 2914 "parser.y"
    {currentIsTemplate = TRUE;}
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 2914 "parser.y"
    {
            if (currentSpec->genc)
                yyerror("Class templates not allowed in a C module");

            if (notSkipping())
            {
                classTmplDef *tcd;

                /*
                 * Make sure there is room for the extra class name argument.
                 */
                if ((yyvsp[(1) - (3)].signature).nrArgs == MAX_NR_ARGS)
                    yyerror("Internal error - increase the value of MAX_NR_ARGS");

                tcd = sipMalloc(sizeof (classTmplDef));
                tcd->sig = (yyvsp[(1) - (3)].signature);
                tcd->cd = (yyvsp[(3) - (3)].klass);
                tcd->next = currentSpec->classtemplates;

                currentSpec->classtemplates = tcd;
            }

            currentIsTemplate = FALSE;
        }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 2940 "parser.y"
    {
            (yyval.signature) = (yyvsp[(3) - (4)].signature);
        }
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 2945 "parser.y"
    {
            if (currentSpec->genc)
                yyerror("Class definition not allowed in a C module");

            if (notSkipping())
                currentSupers = NULL;
        }
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 2951 "parser.y"
    {
            if (notSkipping())
            {
                const char *annos[] = {
                    "Abstract",
                    "AllowNone",
                    "API",
                    "DelayDtor",
                    "Deprecated",
                    "ExportDerived",
                    "External",
                    "FileExtension",
                    "Metatype",
                    "Mixin",
                    "NoDefaultCtors",
                    "PyName",
                    "PyQtFlags",
                    "PyQtInterface",
                    "PyQtNoQMetaObject",
                    "Supertype",
                    "TypeHint",
                    "TypeHintIn",
                    "TypeHintOut",
                    "TypeHintValue",
                    "VirtualErrorHandler",
                    NULL
                };

                checkAnnos(&(yyvsp[(5) - (5)].optflags), annos);

                defineClass((yyvsp[(2) - (5)].scpvalp), currentSupers, &(yyvsp[(5) - (5)].optflags));
                sectionFlags = SECT_IS_PRIVATE;
            }
        }
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 2984 "parser.y"
    {
            if (notSkipping())
                (yyval.klass) = completeClass((yyvsp[(2) - (8)].scpvalp), &(yyvsp[(5) - (8)].optflags), (yyvsp[(7) - (8)].boolean));
        }
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 2998 "parser.y"
    {
            if (notSkipping() && (yyvsp[(1) - (2)].token) == TK_PUBLIC)
            {
                argDef ad;
                classDef *super;
                scopedNameDef *snd = (yyvsp[(2) - (2)].scpvalp);

                /*
                 * This is a hack to allow typedef'ed classes to be used before
                 * we have resolved the typedef definitions.  Unlike elsewhere,
                 * we require that the typedef is defined before being used.
                 */
                for (;;)
                {
                    ad.atype = no_type;
                    ad.argflags = 0;
                    ad.nrderefs = 0;
                    ad.original_type = NULL;

                    searchTypedefs(currentSpec, snd, &ad);

                    if (ad.atype != defined_type)
                        break;

                    if (ad.nrderefs != 0 || isConstArg(&ad) || isReference(&ad))
                        break;

                    snd = ad.u.snd;
                }

                if (ad.atype != no_type)
                    yyerror("Super-class list contains an invalid type");

                /*
                 * Note that passing NULL as the API is a bug.  Instead we
                 * should pass the API of the sub-class being defined,
                 * otherwise we cannot create sub-classes of versioned classes.
                 */
                super = findClass(currentSpec, class_iface, NULL, snd);
                appendToClassList(&currentSupers, super);
            }
        }
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 3042 "parser.y"
    {
        (yyval.token) = TK_PUBLIC;
        }
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 3045 "parser.y"
    {
        (yyval.token) = TK_PUBLIC;
        }
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 3048 "parser.y"
    {
        (yyval.token) = TK_PROTECTED;
        }
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 3051 "parser.y"
    {
        (yyval.token) = TK_PRIVATE;
        }
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 3056 "parser.y"
    {
            (yyval.boolean) = FALSE;
        }
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 3059 "parser.y"
    {
            (yyval.boolean) = TRUE;
        }
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 3077 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentScope()->docstring, (yyvsp[(1) - (1)].codeb));
        }
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 3081 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentScope()->cppcode, (yyvsp[(1) - (1)].codeb));
        }
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 3085 "parser.y"
    {
            if (notSkipping())
                appendCodeBlock(&currentScope()->iff->hdrcode, (yyvsp[(1) - (1)].codeb));
        }
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 3089 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->travcode != NULL)
                    yyerror("%GCTraverseCode already given for class");

                appendCodeBlock(&scope->travcode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 3100 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->clearcode != NULL)
                    yyerror("%GCClearCode already given for class");

                appendCodeBlock(&scope->clearcode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 3111 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->getbufcode != NULL)
                    yyerror("%BIGetBufferCode already given for class");

                appendCodeBlock(&scope->getbufcode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 3122 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->releasebufcode != NULL)
                    yyerror("%BIReleaseBufferCode already given for class");

                appendCodeBlock(&scope->releasebufcode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 3133 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->readbufcode != NULL)
                    yyerror("%BIGetReadBufferCode already given for class");

                appendCodeBlock(&scope->readbufcode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 3144 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->writebufcode != NULL)
                    yyerror("%BIGetWriteBufferCode already given for class");

                appendCodeBlock(&scope->writebufcode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 3155 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->segcountcode != NULL)
                    yyerror("%BIGetSegCountCode already given for class");

                appendCodeBlock(&scope->segcountcode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 3166 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->charbufcode != NULL)
                    yyerror("%BIGetCharBufferCode already given for class");

                appendCodeBlock(&scope->charbufcode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 3177 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->instancecode != NULL)
                    yyerror("%InstanceCode already given for class");

                appendCodeBlock(&scope->instancecode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 3188 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->picklecode != NULL)
                    yyerror("%PickleCode already given for class");

                appendCodeBlock(&scope->picklecode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 3199 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->finalcode != NULL)
                    yyerror("%FinalisationCode already given for class");

                appendCodeBlock(&scope->finalcode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 3210 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->typehintcode != NULL)
                    yyerror("%TypeHintCode already given for class");

                appendCodeBlock(&scope->typehintcode, (yyvsp[(1) - (1)].codeb));
            }
        }
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 3224 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->convtosubcode != NULL)
                    yyerror("Class has more than one %ConvertToSubClassCode directive");

                appendCodeBlock(&scope->convtosubcode, (yyvsp[(2) - (2)].codeb));
            }
        }
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 3235 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->convtocode != NULL)
                    yyerror("Class has more than one %ConvertToTypeCode directive");

                appendCodeBlock(&scope->convtocode, (yyvsp[(2) - (2)].codeb));
            }
        }
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 3246 "parser.y"
    {
            if (notSkipping())
            {
                classDef *scope = currentScope();

                if (scope->convfromcode != NULL)
                    yyerror("Class has more than one %ConvertFromTypeCode directive");

                appendCodeBlock(&scope->convfromcode, (yyvsp[(2) - (2)].codeb));
            }
        }
    break;

  case 399:

/* Line 1806 of yacc.c  */
#line 3257 "parser.y"
    {
            if (currentSpec -> genc)
                yyerror("public section not allowed in a C module");

            if (notSkipping())
                sectionFlags = SECT_IS_PUBLIC | (yyvsp[(2) - (3)].number);
        }
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 3264 "parser.y"
    {
            if (currentSpec -> genc)
                yyerror("protected section not allowed in a C module");

            if (notSkipping())
                sectionFlags = SECT_IS_PROT | (yyvsp[(2) - (3)].number);
        }
    break;

  case 401:

/* Line 1806 of yacc.c  */
#line 3271 "parser.y"
    {
            if (currentSpec -> genc)
                yyerror("private section not allowed in a C module");

            if (notSkipping())
                sectionFlags = SECT_IS_PRIVATE | (yyvsp[(2) - (3)].number);
        }
    break;

  case 402:

/* Line 1806 of yacc.c  */
#line 3278 "parser.y"
    {
            if (currentSpec -> genc)
                yyerror("signals section not allowed in a C module");

            if (notSkipping())
                sectionFlags = SECT_IS_SIGNAL;
        }
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 3287 "parser.y"
    {
            if ((yyvsp[(2) - (3)].property).name == NULL)
                yyerror("A %Property directive must have a 'name' argument");

            if ((yyvsp[(2) - (3)].property).get == NULL)
                yyerror("A %Property directive must have a 'get' argument");

            if (notSkipping())
                addProperty(currentSpec, currentModule, currentScope(),
                        (yyvsp[(2) - (3)].property).name, (yyvsp[(2) - (3)].property).get, (yyvsp[(2) - (3)].property).set, (yyvsp[(3) - (3)].property).docstring);
        }
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 3300 "parser.y"
    {
            (yyval.property) = (yyvsp[(2) - (3)].property);
        }
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 3306 "parser.y"
    {
            (yyval.property) = (yyvsp[(1) - (3)].property);

            switch ((yyvsp[(3) - (3)].property).token)
            {
            case TK_GET: (yyval.property).get = (yyvsp[(3) - (3)].property).get; break;
            case TK_NAME: (yyval.property).name = (yyvsp[(3) - (3)].property).name; break;
            case TK_SET: (yyval.property).set = (yyvsp[(3) - (3)].property).set; break;
            }
        }
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 3318 "parser.y"
    {
            (yyval.property).token = TK_GET;

            (yyval.property).get = (yyvsp[(3) - (3)].text);
            (yyval.property).name = NULL;
            (yyval.property).set = NULL;
        }
    break;

  case 408:

/* Line 1806 of yacc.c  */
#line 3325 "parser.y"
    {
            (yyval.property).token = TK_NAME;

            (yyval.property).get = NULL;
            (yyval.property).name = (yyvsp[(3) - (3)].text);
            (yyval.property).set = NULL;
        }
    break;

  case 409:

/* Line 1806 of yacc.c  */
#line 3332 "parser.y"
    {
            (yyval.property).token = TK_SET;

            (yyval.property).get = NULL;
            (yyval.property).name = NULL;
            (yyval.property).set = (yyvsp[(3) - (3)].text);
        }
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 3341 "parser.y"
    {
            (yyval.property).token = 0;
            (yyval.property).docstring = NULL;
        }
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 3345 "parser.y"
    {
            (yyval.property) = (yyvsp[(2) - (4)].property);
        }
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 3351 "parser.y"
    {
            (yyval.property) = (yyvsp[(1) - (2)].property);

            switch ((yyvsp[(2) - (2)].property).token)
            {
            case TK_DOCSTRING: (yyval.property).docstring = (yyvsp[(2) - (2)].property).docstring; break;
            }
        }
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 3361 "parser.y"
    {
            (yyval.property).token = TK_IF;
        }
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 3364 "parser.y"
    {
            (yyval.property).token = TK_END;
        }
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 3367 "parser.y"
    {
            if (notSkipping())
            {
                (yyval.property).token = TK_DOCSTRING;
                (yyval.property).docstring = (yyvsp[(1) - (1)].codeb);
            }
            else
            {
                (yyval.property).token = 0;
                (yyval.property).docstring = NULL;
            }
        }
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 3385 "parser.y"
    {
            (yyval.number) = 0;
        }
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 3388 "parser.y"
    {
            (yyval.number) = SECT_IS_SLOT;
        }
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 3393 "parser.y"
    {
            /* Note that we allow non-virtual dtors in C modules. */

            if (notSkipping())
            {
                const char *annos[] = {
                    "HoldGIL",
                    "ReleaseGIL",
                    NULL
                };

                classDef *cd = currentScope();

                checkAnnos(&(yyvsp[(8) - (11)].optflags), annos);

                if (strcmp(classBaseName(cd),(yyvsp[(3) - (11)].text)) != 0)
                    yyerror("Destructor doesn't have the same name as its class");

                if (isDtor(cd))
                    yyerror("Destructor has already been defined");

                if (currentSpec -> genc && (yyvsp[(10) - (11)].codeb) == NULL)
                    yyerror("Destructor in C modules must include %MethodCode");

                appendCodeBlock(&cd->dealloccode, (yyvsp[(10) - (11)].codeb));
                appendCodeBlock(&cd->dtorcode, (yyvsp[(11) - (11)].codeb));
                cd -> dtorexceptions = (yyvsp[(6) - (11)].throwlist);

                /*
                 * Note that we don't apply the protected/public hack to dtors
                 * as it (I think) may change the behaviour of the wrapped API.
                 */
                cd->classflags |= sectionFlags;

                if ((yyvsp[(7) - (11)].number))
                {
                    if (!(yyvsp[(1) - (11)].number))
                        yyerror("Abstract destructor must be virtual");

                    setIsAbstractClass(cd);
                }

                /*
                 * The class has a shadow if we have a virtual dtor or some
                 * dtor code.
                 */
                if ((yyvsp[(1) - (11)].number) || (yyvsp[(11) - (11)].codeb) != NULL)
                {
                    if (currentSpec -> genc)
                        yyerror("Virtual destructor or %VirtualCatcherCode not allowed in a C module");

                    setHasShadow(cd);
                }

                if (getReleaseGIL(&(yyvsp[(8) - (11)].optflags)))
                    setIsReleaseGILDtor(cd);
                else if (getHoldGIL(&(yyvsp[(8) - (11)].optflags)))
                    setIsHoldGILDtor(cd);
            }
        }
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 3455 "parser.y"
    {currentCtorIsExplicit = TRUE;}
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 3459 "parser.y"
    {
            /* Note that we allow ctors in C modules. */

            if (notSkipping())
            {
                const char *annos[] = {
                    "API",
                    "Default",
                    "Deprecated",
                    "HoldGIL",
                    "KeywordArgs",
                    "NoDerived",
                    "NoRaisesPyException",
                    "NoTypeHint",
                    "PostHook",
                    "PreHook",
                    "RaisesPyException",
                    "ReleaseGIL",
                    "Transfer",
                    NULL
                };

                checkAnnos(&(yyvsp[(6) - (10)].optflags), annos);

                if (currentSpec -> genc)
                {
                    if ((yyvsp[(10) - (10)].codeb) == NULL && (yyvsp[(3) - (10)].signature).nrArgs != 0)
                        yyerror("Constructors with arguments in C modules must include %MethodCode");

                    if (currentCtorIsExplicit)
                        yyerror("Explicit constructors not allowed in a C module");
                }

                if ((sectionFlags & (SECT_IS_PUBLIC | SECT_IS_PROT | SECT_IS_PRIVATE)) == 0)
                    yyerror("Constructor must be in the public, private or protected sections");

                newCtor(currentModule, (yyvsp[(1) - (10)].text), sectionFlags, &(yyvsp[(3) - (10)].signature), &(yyvsp[(6) - (10)].optflags), (yyvsp[(10) - (10)].codeb), (yyvsp[(5) - (10)].throwlist), (yyvsp[(7) - (10)].optsignature),
                        currentCtorIsExplicit, (yyvsp[(9) - (10)].codeb));
            }

            free((yyvsp[(1) - (10)].text));

            currentCtorIsExplicit = FALSE;
        }
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 3505 "parser.y"
    {
            (yyval.optsignature) = NULL;
        }
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 3508 "parser.y"
    {
            parsingCSignature = TRUE;
        }
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 3510 "parser.y"
    {
            (yyval.optsignature) = sipMalloc(sizeof (signatureDef));

            *(yyval.optsignature) = (yyvsp[(4) - (6)].signature);

            parsingCSignature = FALSE;
        }
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 3519 "parser.y"
    {
            (yyval.optsignature) = NULL;
        }
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 3522 "parser.y"
    {
            parsingCSignature = TRUE;
        }
    break;

  case 431:

/* Line 1806 of yacc.c  */
#line 3524 "parser.y"
    {
            (yyval.optsignature) = sipMalloc(sizeof (signatureDef));

            *(yyval.optsignature) = (yyvsp[(5) - (7)].signature);
            (yyval.optsignature)->result = (yyvsp[(3) - (7)].memArg);

            parsingCSignature = FALSE;
        }
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 3534 "parser.y"
    {
            (yyval.number) = FALSE;
        }
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 3537 "parser.y"
    {
            (yyval.number) = TRUE;
        }
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 3542 "parser.y"
    {
            if (notSkipping())
            {
                applyTypeFlags(currentModule, &(yyvsp[(1) - (15)].memArg), &(yyvsp[(9) - (15)].optflags));

                (yyvsp[(4) - (15)].signature).result = (yyvsp[(1) - (15)].memArg);

                newFunction(currentSpec, currentModule, currentScope(), NULL,
                        sectionFlags, currentIsStatic, currentIsSignal,
                        currentIsSlot, currentOverIsVirt, (yyvsp[(2) - (15)].text), &(yyvsp[(4) - (15)].signature), (yyvsp[(6) - (15)].number), (yyvsp[(8) - (15)].number), &(yyvsp[(9) - (15)].optflags),
                        (yyvsp[(13) - (15)].codeb), (yyvsp[(14) - (15)].codeb), (yyvsp[(15) - (15)].codeb), (yyvsp[(7) - (15)].throwlist), (yyvsp[(10) - (15)].optsignature), (yyvsp[(12) - (15)].codeb));
            }

            currentIsStatic = FALSE;
            currentIsSignal = FALSE;
            currentIsSlot = FALSE;
            currentOverIsVirt = FALSE;
        }
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 3560 "parser.y"
    {
            /*
             * It looks like an assignment operator (though we don't bother to
             * check the types) so make sure it is private.
             */
            if (notSkipping())
            {
                classDef *cd = currentScope();

                if (cd == NULL || !(sectionFlags & SECT_IS_PRIVATE))
                    yyerror("Assignment operators may only be defined as private");

                setCannotAssign(cd);
            }

            currentIsStatic = FALSE;
            currentIsSignal = FALSE;
            currentIsSlot = FALSE;
            currentOverIsVirt = FALSE;
        }
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 3580 "parser.y"
    {
            if (notSkipping())
            {
                classDef *cd = currentScope();

                /*
                 * If the scope is a namespace then make sure the operator is
                 * handled as a global.
                 */
                if (cd != NULL && cd->iff->type == namespace_iface)
                    cd = NULL;

                applyTypeFlags(currentModule, &(yyvsp[(1) - (15)].memArg), &(yyvsp[(10) - (15)].optflags));

                /* Handle the unary '+' and '-' operators. */
                if ((cd != NULL && (yyvsp[(5) - (15)].signature).nrArgs == 0) || (cd == NULL && (yyvsp[(5) - (15)].signature).nrArgs == 1))
                {
                    if (strcmp((yyvsp[(3) - (15)].text), "__add__") == 0)
                        (yyvsp[(3) - (15)].text) = "__pos__";
                    else if (strcmp((yyvsp[(3) - (15)].text), "__sub__") == 0)
                        (yyvsp[(3) - (15)].text) = "__neg__";
                }

                (yyvsp[(5) - (15)].signature).result = (yyvsp[(1) - (15)].memArg);

                newFunction(currentSpec, currentModule, cd, NULL,
                        sectionFlags, currentIsStatic, currentIsSignal,
                        currentIsSlot, currentOverIsVirt, (yyvsp[(3) - (15)].text), &(yyvsp[(5) - (15)].signature), (yyvsp[(7) - (15)].number), (yyvsp[(9) - (15)].number),
                        &(yyvsp[(10) - (15)].optflags), (yyvsp[(13) - (15)].codeb), (yyvsp[(14) - (15)].codeb), (yyvsp[(15) - (15)].codeb), (yyvsp[(8) - (15)].throwlist), (yyvsp[(11) - (15)].optsignature), NULL);
            }

            currentIsStatic = FALSE;
            currentIsSignal = FALSE;
            currentIsSlot = FALSE;
            currentOverIsVirt = FALSE;
        }
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 3616 "parser.y"
    {
            if (notSkipping())
            {
                char *sname;
                classDef *scope = currentScope();

                if (scope == NULL || (yyvsp[(4) - (14)].signature).nrArgs != 0)
                    yyerror("Operator casts must be specified in a class and have no arguments");

                applyTypeFlags(currentModule, &(yyvsp[(2) - (14)].memArg), &(yyvsp[(9) - (14)].optflags));

                switch ((yyvsp[(2) - (14)].memArg).atype)
                {
                case defined_type:
                    sname = NULL;
                    break;

                case bool_type:
                case cbool_type:
                case byte_type:
                case sbyte_type:
                case ubyte_type:
                case short_type:
                case ushort_type:
                case int_type:
                case cint_type:
                case uint_type:
                    sname = "__int__";
                    break;

                case long_type:
                case ulong_type:
                case longlong_type:
                case ulonglong_type:
                    sname = "__long__";
                    break;

                case float_type:
                case cfloat_type:
                case double_type:
                case cdouble_type:
                    sname = "__float__";
                    break;

                default:
                    yyerror("Unsupported operator cast");
                }

                if (sname != NULL)
                {
                    (yyvsp[(4) - (14)].signature).result = (yyvsp[(2) - (14)].memArg);

                    newFunction(currentSpec, currentModule, scope, NULL,
                            sectionFlags, currentIsStatic, currentIsSignal,
                            currentIsSlot, currentOverIsVirt, sname, &(yyvsp[(4) - (14)].signature), (yyvsp[(6) - (14)].number),
                            (yyvsp[(8) - (14)].number), &(yyvsp[(9) - (14)].optflags), (yyvsp[(12) - (14)].codeb), (yyvsp[(13) - (14)].codeb), (yyvsp[(14) - (14)].codeb), (yyvsp[(7) - (14)].throwlist), (yyvsp[(10) - (14)].optsignature), NULL);
                }
                else
                {
                    argList *al;

                    /* Check it doesn't already exist. */
                    for (al = scope->casts; al != NULL; al = al->next)
                        if (compareScopedNames((yyvsp[(2) - (14)].memArg).u.snd, al->arg.u.snd) == 0)
                            yyerror("This operator cast has already been specified in this class");

                    al = sipMalloc(sizeof (argList));
                    al->arg = (yyvsp[(2) - (14)].memArg);
                    al->next = scope->casts;

                    scope->casts = al;
                }
            }

            currentIsStatic = FALSE;
            currentIsSignal = FALSE;
            currentIsSlot = FALSE;
            currentOverIsVirt = FALSE;
        }
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 3697 "parser.y"
    {(yyval.text) = "__add__";}
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 3698 "parser.y"
    {(yyval.text) = "__sub__";}
    break;

  case 440:

/* Line 1806 of yacc.c  */
#line 3699 "parser.y"
    {(yyval.text) = "__mul__";}
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 3700 "parser.y"
    {(yyval.text) = "__div__";}
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 3701 "parser.y"
    {(yyval.text) = "__mod__";}
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 3702 "parser.y"
    {(yyval.text) = "__and__";}
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 3703 "parser.y"
    {(yyval.text) = "__or__";}
    break;

  case 445:

/* Line 1806 of yacc.c  */
#line 3704 "parser.y"
    {(yyval.text) = "__xor__";}
    break;

  case 446:

/* Line 1806 of yacc.c  */
#line 3705 "parser.y"
    {(yyval.text) = "__lshift__";}
    break;

  case 447:

/* Line 1806 of yacc.c  */
#line 3706 "parser.y"
    {(yyval.text) = "__rshift__";}
    break;

  case 448:

/* Line 1806 of yacc.c  */
#line 3707 "parser.y"
    {(yyval.text) = "__iadd__";}
    break;

  case 449:

/* Line 1806 of yacc.c  */
#line 3708 "parser.y"
    {(yyval.text) = "__isub__";}
    break;

  case 450:

/* Line 1806 of yacc.c  */
#line 3709 "parser.y"
    {(yyval.text) = "__imul__";}
    break;

  case 451:

/* Line 1806 of yacc.c  */
#line 3710 "parser.y"
    {(yyval.text) = "__idiv__";}
    break;

  case 452:

/* Line 1806 of yacc.c  */
#line 3711 "parser.y"
    {(yyval.text) = "__imod__";}
    break;

  case 453:

/* Line 1806 of yacc.c  */
#line 3712 "parser.y"
    {(yyval.text) = "__iand__";}
    break;

  case 454:

/* Line 1806 of yacc.c  */
#line 3713 "parser.y"
    {(yyval.text) = "__ior__";}
    break;

  case 455:

/* Line 1806 of yacc.c  */
#line 3714 "parser.y"
    {(yyval.text) = "__ixor__";}
    break;

  case 456:

/* Line 1806 of yacc.c  */
#line 3715 "parser.y"
    {(yyval.text) = "__ilshift__";}
    break;

  case 457:

/* Line 1806 of yacc.c  */
#line 3716 "parser.y"
    {(yyval.text) = "__irshift__";}
    break;

  case 458:

/* Line 1806 of yacc.c  */
#line 3717 "parser.y"
    {(yyval.text) = "__invert__";}
    break;

  case 459:

/* Line 1806 of yacc.c  */
#line 3718 "parser.y"
    {(yyval.text) = "__call__";}
    break;

  case 460:

/* Line 1806 of yacc.c  */
#line 3719 "parser.y"
    {(yyval.text) = "__getitem__";}
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 3720 "parser.y"
    {(yyval.text) = "__lt__";}
    break;

  case 462:

/* Line 1806 of yacc.c  */
#line 3721 "parser.y"
    {(yyval.text) = "__le__";}
    break;

  case 463:

/* Line 1806 of yacc.c  */
#line 3722 "parser.y"
    {(yyval.text) = "__eq__";}
    break;

  case 464:

/* Line 1806 of yacc.c  */
#line 3723 "parser.y"
    {(yyval.text) = "__ne__";}
    break;

  case 465:

/* Line 1806 of yacc.c  */
#line 3724 "parser.y"
    {(yyval.text) = "__gt__";}
    break;

  case 466:

/* Line 1806 of yacc.c  */
#line 3725 "parser.y"
    {(yyval.text) = "__ge__";}
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 3728 "parser.y"
    {
            (yyval.number) = FALSE;
        }
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 3731 "parser.y"
    {
            (yyval.number) = TRUE;
        }
    break;

  case 469:

/* Line 1806 of yacc.c  */
#line 3736 "parser.y"
    {
            (yyval.number) = 0;
        }
    break;

  case 470:

/* Line 1806 of yacc.c  */
#line 3739 "parser.y"
    {
            if ((yyvsp[(2) - (2)].number) != 0)
                yyerror("Abstract virtual function '= 0' expected");

            (yyval.number) = TRUE;
        }
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 3747 "parser.y"
    {
            (yyval.optflags).nrFlags = 0;
        }
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 3750 "parser.y"
    {
            (yyval.optflags) = (yyvsp[(2) - (3)].optflags);
        }
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 3756 "parser.y"
    {
            (yyval.optflags).flags[0] = (yyvsp[(1) - (1)].flag);
            (yyval.optflags).nrFlags = 1;
        }
    break;

  case 474:

/* Line 1806 of yacc.c  */
#line 3760 "parser.y"
    {
            /* Check there is room. */

            if ((yyvsp[(1) - (3)].optflags).nrFlags == MAX_NR_FLAGS)
                yyerror("Too many optional flags");

            (yyval.optflags) = (yyvsp[(1) - (3)].optflags);

            (yyval.optflags).flags[(yyval.optflags).nrFlags++] = (yyvsp[(3) - (3)].flag);
        }
    break;

  case 475:

/* Line 1806 of yacc.c  */
#line 3772 "parser.y"
    {
            (yyval.flag).ftype = bool_flag;
            (yyval.flag).fname = (yyvsp[(1) - (1)].text);
        }
    break;

  case 476:

/* Line 1806 of yacc.c  */
#line 3776 "parser.y"
    {
            (yyval.flag) = (yyvsp[(3) - (3)].flag);
            (yyval.flag).fname = (yyvsp[(1) - (3)].text);
        }
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 3782 "parser.y"
    {
            (yyval.flag).ftype = (strchr((yyvsp[(1) - (1)].text), '.') != NULL) ? dotted_name_flag : name_flag;
            (yyval.flag).fvalue.sval = (yyvsp[(1) - (1)].text);
        }
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 3786 "parser.y"
    {
            apiVersionRangeDef *avd;
            int from, to;

            (yyval.flag).ftype = api_range_flag;

            /* Check that the API is known. */
            if ((avd = findAPI(currentSpec, (yyvsp[(1) - (5)].text))) == NULL)
                yyerror("unknown API name in API annotation");

            if (inMainModule())
                setIsUsedName(avd->api_name);

            /* Unbounded values are represented by 0. */
            if ((from = (yyvsp[(3) - (5)].number)) < 0)
                from = 0;

            if ((to = (yyvsp[(5) - (5)].number)) < 0)
                to = 0;

            (yyval.flag).fvalue.aval = convertAPIRange(currentModule, avd->api_name,
                    from, to);
        }
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 3809 "parser.y"
    {
            (yyval.flag).ftype = string_flag;
            (yyval.flag).fvalue.sval = convertFeaturedString((yyvsp[(1) - (1)].text));
        }
    break;

  case 480:

/* Line 1806 of yacc.c  */
#line 3813 "parser.y"
    {
            (yyval.flag).ftype = integer_flag;
            (yyval.flag).fvalue.ival = (yyvsp[(1) - (1)].number);
        }
    break;

  case 481:

/* Line 1806 of yacc.c  */
#line 3819 "parser.y"
    {
            (yyval.codeb) = NULL;
        }
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 3822 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 3827 "parser.y"
    {
            (yyval.codeb) = NULL;
        }
    break;

  case 484:

/* Line 1806 of yacc.c  */
#line 3830 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 3835 "parser.y"
    {
            (yyval.codeb) = NULL;
        }
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 3838 "parser.y"
    {
            (yyval.codeb) = (yyvsp[(2) - (2)].codeb);
        }
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 3843 "parser.y"
    {
            int a, nrrxcon, nrrxdis, nrslotcon, nrslotdis, nrarray, nrarraysize;

            nrrxcon = nrrxdis = nrslotcon = nrslotdis = nrarray = nrarraysize = 0;

            for (a = 0; a < (yyvsp[(1) - (1)].signature).nrArgs; ++a)
            {
                argDef *ad = &(yyvsp[(1) - (1)].signature).args[a];

                switch (ad -> atype)
                {
                case rxcon_type:
                    ++nrrxcon;
                    break;

                case rxdis_type:
                    ++nrrxdis;
                    break;

                case slotcon_type:
                    ++nrslotcon;
                    break;

                case slotdis_type:
                    ++nrslotdis;
                    break;

                /* Suppress a compiler warning. */
                default:
                    ;
                }

                if (isArray(ad))
                    ++nrarray;

                if (isArraySize(ad))
                    ++nrarraysize;
            }

            if (nrrxcon != nrslotcon || nrrxcon > 1)
                yyerror("SIP_RXOBJ_CON and SIP_SLOT_CON must both be given and at most once");

            if (nrrxdis != nrslotdis || nrrxdis > 1)
                yyerror("SIP_RXOBJ_DIS and SIP_SLOT_DIS must both be given and at most once");

            if (nrarray != nrarraysize || nrarray > 1)
                yyerror("/Array/ and /ArraySize/ must both be given and at most once");

            (yyval.signature) = (yyvsp[(1) - (1)].signature);
        }
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 3895 "parser.y"
    {
            /* No arguments. */

            (yyval.signature).nrArgs = 0;
        }
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 3900 "parser.y"
    {
            /* The single or first argument. */

            (yyval.signature).args[0] = (yyvsp[(1) - (1)].memArg);
            (yyval.signature).nrArgs = 1;
        }
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 3906 "parser.y"
    {
            /* Check that it wasn't ...(,arg...). */
            if ((yyvsp[(1) - (3)].signature).nrArgs == 0)
                yyerror("First argument of the list is missing");

            /*
             * If this argument has no default value, then the
             * previous one mustn't either.
             */
            if ((yyvsp[(3) - (3)].memArg).defval == NULL && (yyvsp[(1) - (3)].signature).args[(yyvsp[(1) - (3)].signature).nrArgs - 1].defval != NULL)
                yyerror("Compulsory argument given after optional argument");

            /* Check there is room. */
            if ((yyvsp[(1) - (3)].signature).nrArgs == MAX_NR_ARGS)
                yyerror("Internal error - increase the value of MAX_NR_ARGS");

            (yyval.signature) = (yyvsp[(1) - (3)].signature);

            (yyval.signature).args[(yyval.signature).nrArgs] = (yyvsp[(3) - (3)].memArg);
            (yyval.signature).nrArgs++;
        }
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 3929 "parser.y"
    {
            deprecated("SIP_SIGNAL is deprecated\n");
            checkNoAnnos(&(yyvsp[(3) - (4)].optflags), "SIP_SIGNAL has no annotations");

            (yyval.memArg).atype = signal_type;
            (yyval.memArg).argflags = ARG_IS_CONST;
            (yyval.memArg).nrderefs = 0;
            (yyval.memArg).name = cacheName(currentSpec, (yyvsp[(2) - (4)].text));
            (yyval.memArg).defval = (yyvsp[(4) - (4)].valp);

            currentSpec -> sigslots = TRUE;
        }
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 3941 "parser.y"
    {
            deprecated("SIP_SLOT is deprecated\n");
            checkNoAnnos(&(yyvsp[(3) - (4)].optflags), "SIP_SLOT has no annotations");

            (yyval.memArg).atype = slot_type;
            (yyval.memArg).argflags = ARG_IS_CONST;
            (yyval.memArg).nrderefs = 0;
            (yyval.memArg).name = cacheName(currentSpec, (yyvsp[(2) - (4)].text));
            (yyval.memArg).defval = (yyvsp[(4) - (4)].valp);

            currentSpec -> sigslots = TRUE;
        }
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 3953 "parser.y"
    {
            deprecated("SIP_ANYSLOT is deprecated\n");
            checkNoAnnos(&(yyvsp[(3) - (4)].optflags), "SIP_ANYSLOT has no annotations");

            (yyval.memArg).atype = anyslot_type;
            (yyval.memArg).argflags = ARG_IS_CONST;
            (yyval.memArg).nrderefs = 0;
            (yyval.memArg).name = cacheName(currentSpec, (yyvsp[(2) - (4)].text));
            (yyval.memArg).defval = (yyvsp[(4) - (4)].valp);

            currentSpec -> sigslots = TRUE;
        }
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 3965 "parser.y"
    {
            const char *annos[] = {
                "SingleShot",
                NULL
            };

            deprecated("SIP_RXOBJ_CON is deprecated\n");
            checkAnnos(&(yyvsp[(3) - (3)].optflags), annos);

            (yyval.memArg).atype = rxcon_type;
            (yyval.memArg).argflags = 0;
            (yyval.memArg).nrderefs = 0;
            (yyval.memArg).name = cacheName(currentSpec, (yyvsp[(2) - (3)].text));

            if (getOptFlag(&(yyvsp[(3) - (3)].optflags), "SingleShot", bool_flag) != NULL)
                (yyval.memArg).argflags |= ARG_SINGLE_SHOT;

            currentSpec -> sigslots = TRUE;
        }
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 3984 "parser.y"
    {
            deprecated("SIP_RXOBJ_DIS is deprecated\n");
            checkNoAnnos(&(yyvsp[(3) - (3)].optflags), "SIP_RXOBJ_DIS has no annotations");

            (yyval.memArg).atype = rxdis_type;
            (yyval.memArg).argflags = 0;
            (yyval.memArg).nrderefs = 0;
            (yyval.memArg).name = cacheName(currentSpec, (yyvsp[(2) - (3)].text));

            currentSpec -> sigslots = TRUE;
        }
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 3995 "parser.y"
    {
            deprecated("SIP_SLOT_CON is deprecated\n");
            checkNoAnnos(&(yyvsp[(6) - (6)].optflags), "SIP_SLOT_CON has no annotations");

            (yyval.memArg).atype = slotcon_type;
            (yyval.memArg).argflags = ARG_IS_CONST;
            (yyval.memArg).nrderefs = 0;
            (yyval.memArg).name = cacheName(currentSpec, (yyvsp[(5) - (6)].text));

            memset(&(yyvsp[(3) - (6)].signature).result, 0, sizeof (argDef));
            (yyvsp[(3) - (6)].signature).result.atype = void_type;

            (yyval.memArg).u.sa = sipMalloc(sizeof (signatureDef));
            *(yyval.memArg).u.sa = (yyvsp[(3) - (6)].signature);

            currentSpec -> sigslots = TRUE;
        }
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 4012 "parser.y"
    {
            deprecated("SIP_SLOT_DIS is deprecated\n");
            checkNoAnnos(&(yyvsp[(6) - (6)].optflags), "SIP_SLOT_DIS has no annotations");

            (yyval.memArg).atype = slotdis_type;
            (yyval.memArg).argflags = ARG_IS_CONST;
            (yyval.memArg).nrderefs = 0;
            (yyval.memArg).name = cacheName(currentSpec, (yyvsp[(5) - (6)].text));

            memset(&(yyvsp[(3) - (6)].signature).result, 0, sizeof (argDef));
            (yyvsp[(3) - (6)].signature).result.atype = void_type;

            (yyval.memArg).u.sa = sipMalloc(sizeof (signatureDef));
            *(yyval.memArg).u.sa = (yyvsp[(3) - (6)].signature);

            currentSpec -> sigslots = TRUE;
        }
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 4029 "parser.y"
    {
            deprecated("SIP_QOBJECT is deprecated\n");
            checkNoAnnos(&(yyvsp[(3) - (3)].optflags), "SIP_QOBJECT has no annotations");

            (yyval.memArg).atype = qobject_type;
            (yyval.memArg).argflags = 0;
            (yyval.memArg).nrderefs = 0;
            (yyval.memArg).name = cacheName(currentSpec, (yyvsp[(2) - (3)].text));
        }
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 4038 "parser.y"
    {
            (yyval.memArg) = (yyvsp[(1) - (2)].memArg);
            (yyval.memArg).defval = (yyvsp[(2) - (2)].valp);
        }
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 4045 "parser.y"
    {currentIsSignal = TRUE;}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 4046 "parser.y"
    {currentIsSlot = TRUE;}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 4051 "parser.y"
    {currentIsStatic = TRUE;}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 4061 "parser.y"
    {currentOverIsVirt = TRUE;}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 4065 "parser.y"
    {
            if (notSkipping())
            {
                const char *annos[] = {
                    "DocType",
                    "Encoding",
                    "NoSetter",
                    "NoTypeHint",
                    "PyInt",
                    "PyName",
                    "TypeHint",
                    NULL
                };

                checkAnnos(&(yyvsp[(3) - (8)].optflags), annos);

                if ((yyvsp[(6) - (8)].codeb) != NULL)
                {
                    if ((yyvsp[(4) - (8)].variable).access_code != NULL)
                        yyerror("%AccessCode already defined");

                    (yyvsp[(4) - (8)].variable).access_code = (yyvsp[(6) - (8)].codeb);

                    deprecated("%AccessCode should be used as a sub-directive");
                }

                if ((yyvsp[(7) - (8)].codeb) != NULL)
                {
                    if ((yyvsp[(4) - (8)].variable).get_code != NULL)
                        yyerror("%GetCode already defined");

                    (yyvsp[(4) - (8)].variable).get_code = (yyvsp[(7) - (8)].codeb);

                    deprecated("%GetCode should be used as a sub-directive");
                }

                if ((yyvsp[(8) - (8)].codeb) != NULL)
                {
                    if ((yyvsp[(4) - (8)].variable).set_code != NULL)
                        yyerror("%SetCode already defined");

                    (yyvsp[(4) - (8)].variable).set_code = (yyvsp[(8) - (8)].codeb);

                    deprecated("%SetCode should be used as a sub-directive");
                }

                newVar(currentSpec, currentModule, (yyvsp[(2) - (8)].text), currentIsStatic, &(yyvsp[(1) - (8)].memArg),
                        &(yyvsp[(3) - (8)].optflags), (yyvsp[(4) - (8)].variable).access_code, (yyvsp[(4) - (8)].variable).get_code, (yyvsp[(4) - (8)].variable).set_code,
                        sectionFlags);
            }

            currentIsStatic = FALSE;
        }
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 4120 "parser.y"
    {
            (yyval.variable).token = 0;
            (yyval.variable).access_code = NULL;
            (yyval.variable).get_code = NULL;
            (yyval.variable).set_code = NULL;
        }
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 4126 "parser.y"
    {
            (yyval.variable) = (yyvsp[(2) - (3)].variable);
        }
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 4132 "parser.y"
    {
            (yyval.variable) = (yyvsp[(1) - (2)].variable);

            switch ((yyvsp[(2) - (2)].variable).token)
            {
            case TK_ACCESSCODE: (yyval.variable).access_code = (yyvsp[(2) - (2)].variable).access_code; break;
            case TK_GETCODE: (yyval.variable).get_code = (yyvsp[(2) - (2)].variable).get_code; break;
            case TK_SETCODE: (yyval.variable).set_code = (yyvsp[(2) - (2)].variable).set_code; break;
            }
        }
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 4144 "parser.y"
    {
            (yyval.variable).token = TK_IF;
        }
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 4147 "parser.y"
    {
            (yyval.variable).token = TK_END;
        }
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 4150 "parser.y"
    {
            if (notSkipping())
            {
                (yyval.variable).token = TK_ACCESSCODE;
                (yyval.variable).access_code = (yyvsp[(2) - (2)].codeb);
            }
            else
            {
                (yyval.variable).token = 0;
                (yyval.variable).access_code = NULL;
            }

            (yyval.variable).get_code = NULL;
            (yyval.variable).set_code = NULL;
        }
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 4165 "parser.y"
    {
            if (notSkipping())
            {
                (yyval.variable).token = TK_GETCODE;
                (yyval.variable).get_code = (yyvsp[(2) - (2)].codeb);
            }
            else
            {
                (yyval.variable).token = 0;
                (yyval.variable).get_code = NULL;
            }

            (yyval.variable).access_code = NULL;
            (yyval.variable).set_code = NULL;
        }
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 4180 "parser.y"
    {
            if (notSkipping())
            {
                (yyval.variable).token = TK_SETCODE;
                (yyval.variable).set_code = (yyvsp[(2) - (2)].codeb);
            }
            else
            {
                (yyval.variable).token = 0;
                (yyval.variable).set_code = NULL;
            }

            (yyval.variable).access_code = NULL;
            (yyval.variable).get_code = NULL;
        }
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 4197 "parser.y"
    {
            (yyval.memArg) = (yyvsp[(2) - (4)].memArg);
            add_derefs(&(yyval.memArg), &(yyvsp[(3) - (4)].memArg));
            (yyval.memArg).argflags |= ARG_IS_CONST | (yyvsp[(4) - (4)].number);
        }
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 4202 "parser.y"
    {
            (yyval.memArg) = (yyvsp[(1) - (3)].memArg);
            add_derefs(&(yyval.memArg), &(yyvsp[(2) - (3)].memArg));
            (yyval.memArg).argflags |= (yyvsp[(3) - (3)].number);

            /* PyObject * is a synonym for SIP_PYOBJECT. */
            if ((yyvsp[(1) - (3)].memArg).atype == defined_type && strcmp((yyvsp[(1) - (3)].memArg).u.snd->name, "PyObject") == 0 && (yyvsp[(1) - (3)].memArg).u.snd->next == NULL && (yyvsp[(2) - (3)].memArg).nrderefs == 1 && (yyvsp[(3) - (3)].number) == 0)
            {
                (yyval.memArg).atype = pyobject_type;
                (yyval.memArg).nrderefs = 0;
            }
        }
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 4216 "parser.y"
    {
            const char *annos[] = {
                "AllowNone",
                "Array",
                "ArraySize",
                "Constrained",
                "DisallowNone",
                "DocType",
                "DocValue",
                "Encoding",
                "GetWrapper",
                "In",
                "KeepReference",
                "NoCopy",
                "Out",
                "PyInt",
                "ResultSize",
                "Transfer",
                "TransferBack",
                "TransferThis",
                "TypeHint",
                "TypeHintIn",
                "TypeHintOut",
                "TypeHintValue",
                NULL
            };

            checkAnnos(&(yyvsp[(3) - (3)].optflags), annos);

            (yyval.memArg) = (yyvsp[(1) - (3)].memArg);
            (yyval.memArg).name = cacheName(currentSpec, (yyvsp[(2) - (3)].text));

            handleKeepReference(&(yyvsp[(3) - (3)].optflags), &(yyval.memArg), currentModule);

            if (getAllowNone(&(yyvsp[(3) - (3)].optflags)))
                (yyval.memArg).argflags |= ARG_ALLOW_NONE;

            if (getDisallowNone(&(yyvsp[(3) - (3)].optflags)))
                (yyval.memArg).argflags |= ARG_DISALLOW_NONE;

            if (getOptFlag(&(yyvsp[(3) - (3)].optflags),"GetWrapper",bool_flag) != NULL)
                (yyval.memArg).argflags |= ARG_GET_WRAPPER;

            if (getOptFlag(&(yyvsp[(3) - (3)].optflags),"Array",bool_flag) != NULL)
                (yyval.memArg).argflags |= ARG_ARRAY;

            if (getOptFlag(&(yyvsp[(3) - (3)].optflags),"ArraySize",bool_flag) != NULL)
                (yyval.memArg).argflags |= ARG_ARRAY_SIZE;

            if (getTransfer(&(yyvsp[(3) - (3)].optflags)))
                (yyval.memArg).argflags |= ARG_XFERRED;

            if (getOptFlag(&(yyvsp[(3) - (3)].optflags),"TransferThis",bool_flag) != NULL)
                (yyval.memArg).argflags |= ARG_THIS_XFERRED;

            if (getOptFlag(&(yyvsp[(3) - (3)].optflags),"TransferBack",bool_flag) != NULL)
                (yyval.memArg).argflags |= ARG_XFERRED_BACK;

            if (getOptFlag(&(yyvsp[(3) - (3)].optflags),"In",bool_flag) != NULL)
                (yyval.memArg).argflags |= ARG_IN;

            if (getOptFlag(&(yyvsp[(3) - (3)].optflags),"Out",bool_flag) != NULL)
                (yyval.memArg).argflags |= ARG_OUT;

            if (getOptFlag(&(yyvsp[(3) - (3)].optflags), "ResultSize", bool_flag) != NULL)
                (yyval.memArg).argflags |= ARG_RESULT_SIZE;

            if (getOptFlag(&(yyvsp[(3) - (3)].optflags), "NoCopy", bool_flag) != NULL)
                (yyval.memArg).argflags |= ARG_NO_COPY;

            if (getOptFlag(&(yyvsp[(3) - (3)].optflags),"Constrained",bool_flag) != NULL)
            {
                (yyval.memArg).argflags |= ARG_CONSTRAINED;

                switch ((yyval.memArg).atype)
                {
                case bool_type:
                    (yyval.memArg).atype = cbool_type;
                    break;

                case int_type:
                    (yyval.memArg).atype = cint_type;
                    break;

                case float_type:
                    (yyval.memArg).atype = cfloat_type;
                    break;

                case double_type:
                    (yyval.memArg).atype = cdouble_type;
                    break;

                /* Suppress a compiler warning. */
                default:
                    ;
                }
            }

            applyTypeFlags(currentModule, &(yyval.memArg), &(yyvsp[(3) - (3)].optflags));
            (yyval.memArg).typehint_value = getTypeHintValue(&(yyvsp[(3) - (3)].optflags));
        }
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 4319 "parser.y"
    {
            (yyval.number) = 0;
        }
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 4322 "parser.y"
    {
            if (currentSpec -> genc)
                yyerror("References not allowed in a C module");

            (yyval.number) = ARG_IS_REF;
        }
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 4330 "parser.y"
    {
            (yyval.memArg).nrderefs = 0;
        }
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 4333 "parser.y"
    {
            add_new_deref(&(yyval.memArg), &(yyvsp[(1) - (3)].memArg), TRUE);
        }
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 4336 "parser.y"
    {
            add_new_deref(&(yyval.memArg), &(yyvsp[(1) - (2)].memArg), FALSE);
        }
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 4341 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = defined_type;
            (yyval.memArg).u.snd = (yyvsp[(1) - (1)].scpvalp);

            /* Try and resolve typedefs as early as possible. */
            resolveAnyTypedef(currentSpec, &(yyval.memArg));
        }
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 4349 "parser.y"
    {
            templateDef *td;

            td = sipMalloc(sizeof(templateDef));
            td->fqname = (yyvsp[(1) - (4)].scpvalp);
            td->types = (yyvsp[(3) - (4)].signature);

            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = template_type;
            (yyval.memArg).u.td = td;
        }
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 4360 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));

            /* In a C module all structures must be defined. */
            if (currentSpec -> genc)
            {
                (yyval.memArg).atype = defined_type;
                (yyval.memArg).u.snd = (yyvsp[(2) - (2)].scpvalp);
            }
            else
            {
                (yyval.memArg).atype = struct_type;
                (yyval.memArg).u.sname = (yyvsp[(2) - (2)].scpvalp);
            }
        }
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 4375 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = ushort_type;
        }
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 4379 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = short_type;
        }
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 4383 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = uint_type;
        }
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 4387 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = uint_type;
        }
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 4391 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = int_type;
        }
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 4395 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = long_type;
        }
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 4399 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = ulong_type;
        }
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 4403 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = longlong_type;
        }
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 4407 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = ulonglong_type;
        }
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 4411 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = float_type;
        }
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 4415 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = double_type;
        }
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 4419 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = bool_type;
        }
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 4423 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = sstring_type;
        }
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 4427 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = ustring_type;
        }
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 4431 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = string_type;
        }
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 4435 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = wstring_type;
        }
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 4439 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = void_type;
        }
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 4443 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = pyobject_type;
        }
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 4447 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = pytuple_type;
        }
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 4451 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = pylist_type;
        }
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 4455 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = pydict_type;
        }
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 4459 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = pycallable_type;
        }
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 4463 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = pyslice_type;
        }
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 4467 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = pytype_type;
        }
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 4471 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = pybuffer_type;
        }
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 4475 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = ssize_type;
        }
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 4479 "parser.y"
    {
            memset(&(yyval.memArg), 0, sizeof (argDef));
            (yyval.memArg).atype = ellipsis_type;
        }
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 4485 "parser.y"
    {
            /* The single or first type. */

            (yyval.signature).args[0] = (yyvsp[(1) - (1)].memArg);
            (yyval.signature).nrArgs = 1;
        }
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 4491 "parser.y"
    {
            /* Check there is nothing after an ellipsis. */
            if ((yyvsp[(1) - (3)].signature).args[(yyvsp[(1) - (3)].signature).nrArgs - 1].atype == ellipsis_type)
                yyerror("An ellipsis must be at the end of the argument list");

            /* Check there is room. */
            if ((yyvsp[(1) - (3)].signature).nrArgs == MAX_NR_ARGS)
                yyerror("Internal error - increase the value of MAX_NR_ARGS");

            (yyval.signature) = (yyvsp[(1) - (3)].signature);

            (yyval.signature).args[(yyval.signature).nrArgs] = (yyvsp[(3) - (3)].memArg);
            (yyval.signature).nrArgs++;
        }
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 4507 "parser.y"
    {
            (yyval.throwlist) = NULL;
        }
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 4510 "parser.y"
    {
            if (currentSpec->genc)
                yyerror("Exceptions not allowed in a C module");

            (yyval.throwlist) = (yyvsp[(3) - (4)].throwlist);
        }
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 4518 "parser.y"
    {
            /* Empty list so use a blank. */

            (yyval.throwlist) = sipMalloc(sizeof (throwArgs));
            (yyval.throwlist) -> nrArgs = 0;
        }
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 4524 "parser.y"
    {
            /* The only or first exception. */

            (yyval.throwlist) = sipMalloc(sizeof (throwArgs));
            (yyval.throwlist) -> nrArgs = 1;
            (yyval.throwlist) -> args[0] = findException(currentSpec, (yyvsp[(1) - (1)].scpvalp), FALSE);
        }
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 4531 "parser.y"
    {
            /* Check that it wasn't ...(,arg...). */

            if ((yyvsp[(1) - (3)].throwlist) -> nrArgs == 0)
                yyerror("First exception of throw specifier is missing");

            /* Check there is room. */

            if ((yyvsp[(1) - (3)].throwlist) -> nrArgs == MAX_NR_ARGS)
                yyerror("Internal error - increase the value of MAX_NR_ARGS");

            (yyval.throwlist) = (yyvsp[(1) - (3)].throwlist);
            (yyval.throwlist) -> args[(yyval.throwlist) -> nrArgs++] = findException(currentSpec, (yyvsp[(3) - (3)].scpvalp), FALSE);
        }
    break;



/* Line 1806 of yacc.c  */
#line 9003 "../parser.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 4547 "parser.y"



/*
 * Parse the specification.
 */
void parse(sipSpec *spec, FILE *fp, char *filename, stringList *tsl,
        stringList *bsl, stringList *xfl, KwArgs kwArgs, int protHack)
{
    classTmplDef *tcd;

    /* Initialise the spec. */
 
    memset(spec, 0, sizeof (sipSpec));
    spec->genc = -1;

    currentSpec = spec;
    backstops = bsl;
    neededQualifiers = tsl;
    excludedQualifiers = xfl;
    currentModule = NULL;
    currentMappedType = NULL;
    currentOverIsVirt = FALSE;
    currentCtorIsExplicit = FALSE;
    currentIsStatic = FALSE;
    currentIsSignal = FALSE;
    currentIsSlot = FALSE;
    currentIsTemplate = FALSE;
    previousFile = NULL;
    skipStackPtr = 0;
    currentScopeIdx = 0;
    sectionFlags = 0;
    defaultKwArgs = kwArgs;
    makeProtPublic = protHack;

    newModule(fp, filename);
    spec->module = currentModule;

    yyparse();

    handleEOF();
    handleEOM();

    /*
     * Go through each template class and remove it from the list of classes.
     */
    for (tcd = spec->classtemplates; tcd != NULL; tcd = tcd->next)
    {
        classDef **cdp;

        for (cdp = &spec->classes; *cdp != NULL; cdp = &(*cdp)->next)
            if (*cdp == tcd->cd)
            {
                ifaceFileDef **ifdp;

                /* Remove the interface file as well. */
                for (ifdp = &spec->ifacefiles; *ifdp != NULL; ifdp = &(*ifdp)->next)
                    if (*ifdp == tcd->cd->iff)
                    {
                        *ifdp = (*ifdp)->next;
                        break;
                    }

                *cdp = (*cdp)->next;
                break;
            }
    }
}


/*
 * Tell the parser that a complete file has now been read.
 */
void parserEOF(const char *name, parserContext *pc)
{
    previousFile = sipStrdup(name);
    currentContext = *pc;
}


/*
 * Append a class definition to a class list if it doesn't already appear.
 * Append is needed specifically for the list of super-classes because the
 * order is important to Python.
 */
void appendToClassList(classList **clp,classDef *cd)
{
    classList *new;

    /* Find the end of the list. */

    while (*clp != NULL)
    {
        if ((*clp) -> cd == cd)
            return;

        clp = &(*clp) -> next;
    }

    new = sipMalloc(sizeof (classList));

    new -> cd = cd;
    new -> next = NULL;

    *clp = new;
}


/*
 * Create a new module for the current specification and make it current.
 */
static void newModule(FILE *fp, const char *filename)
{
    moduleDef *mod;

    parseFile(fp, filename, currentModule, FALSE);

    mod = allocModule();
    mod->file = filename;

    if (currentModule != NULL)
        mod->defexception = currentModule->defexception;

    currentModule = mod;
}


/*
 * Allocate and initialise the memory for a new module.
 */
static moduleDef *allocModule()
{
    moduleDef *newmod, **tailp;

    newmod = sipMalloc(sizeof (moduleDef));

    newmod->version = -1;
    newmod->defdocstring = raw;
    newmod->encoding = no_type;
    newmod->nrvirthandlers = -1;
    newmod->next_key = -1;

    /*
     * The consolidated module support needs these to be in order that they
     * appeared.
     */
    for (tailp = &currentSpec->modules; *tailp != NULL; tailp = &(*tailp)->next)
        ;

    *tailp = newmod;

    return newmod;
}


/*
 * Switch to parsing a new file.
 */
static void parseFile(FILE *fp, const char *name, moduleDef *prevmod,
        int optional)
{
    parserContext pc;

    pc.filename = name;
    pc.ifdepth = skipStackPtr;
    pc.prevmod = prevmod;

    if (setInputFile(fp, &pc, optional))
        currentContext = pc;
}


/*
 * Find an interface file, or create a new one.
 */
ifaceFileDef *findIfaceFile(sipSpec *pt, moduleDef *mod, scopedNameDef *fqname,
        ifaceFileType iftype, apiVersionRangeDef *api_range, argDef *ad)
{
    ifaceFileDef *iff, *first_alt = NULL;

    /* See if the name is already used. */

    for (iff = pt->ifacefiles; iff != NULL; iff = iff->next)
    {
        if (compareScopedNames(iff->fqcname, fqname) != 0)
            continue;

        /*
         * If they are both versioned then assume the user knows what they are
         * doing.
         */
        if (iff->api_range != NULL && api_range != NULL && iff->module == mod)
        {
            /* Remember the first of the alternate APIs. */
            if ((first_alt = iff->first_alt) == NULL)
                first_alt = iff;

            break;
        }

        /*
         * They must be the same type except that we allow a class if we want
         * an exception.  This is because we allow classes to be used before
         * they are defined.
         */
        if (iff->type != iftype)
            if (iftype != exception_iface || iff->type != class_iface)
                yyerror("A class, exception, namespace or mapped type has already been defined with the same name");

        /* Ignore an external class declared in another module. */
        if (iftype == class_iface && iff->module != mod)
        {
            classDef *cd;

            for (cd = pt->classes; cd != NULL; cd = cd->next)
                if (cd->iff == iff)
                    break;

            if (cd != NULL && iff->module != NULL && isExternal(cd))
                continue;
        }

        /*
         * If this is a mapped type with the same name defined in a different
         * module, then check that this type isn't the same as any of the
         * mapped types defined in that module.
         */
        if (iftype == mappedtype_iface && iff->module != mod)
        {
            mappedTypeDef *mtd;

            /*
             * This is a bit of a cheat.  With consolidated modules it's
             * possible to have two implementations of a mapped type in
             * different branches of the module hierarchy.  We assume that, if
             * there really are multiple implementations in the same branch,
             * then it will be picked up in a non-consolidated build.
             */
            if (isConsolidated(pt->module))
                continue;

            for (mtd = pt->mappedtypes; mtd != NULL; mtd = mtd->next)
            {
                if (mtd->iff != iff)
                    continue;

                if (ad->atype != template_type ||
                    mtd->type.atype != template_type ||
                    sameBaseType(ad, &mtd->type))
                    yyerror("Mapped type has already been defined in another module");
            }

            /*
             * If we got here then we have a mapped type based on an existing
             * template, but with unique parameters.  We don't want to use
             * interface files from other modules, so skip this one.
             */

            continue;
        }

        /* Ignore a namespace defined in another module. */
        if (iftype == namespace_iface && iff->module != mod)
            continue;

        return iff;
    }

    iff = sipMalloc(sizeof (ifaceFileDef));

    iff->name = cacheName(pt, scopedNameToString(fqname));
    iff->api_range = api_range;

    if (first_alt != NULL)
    {
        iff->first_alt = first_alt;
        iff->next_alt = first_alt->next_alt;

        first_alt->next_alt = iff;
    }
    else
    {
        /* This is the first alternate so point to itself. */
        iff->first_alt = iff;
    }

    iff->type = iftype;
    iff->ifacenr = -1;
    iff->fqcname = fqname;
    iff->module = NULL;
    iff->hdrcode = NULL;
    iff->used = NULL;
    iff->file_extension = NULL;
    iff->next = pt->ifacefiles;

    pt->ifacefiles = iff;

    return iff;
}


/*
 * Find a class definition in a parse tree.
 */
static classDef *findClass(sipSpec *pt, ifaceFileType iftype,
        apiVersionRangeDef *api_range, scopedNameDef *fqname)
{
    return findClassWithInterface(pt, findIfaceFile(pt, currentModule, fqname, iftype, api_range, NULL));
}


/*
 * Find a class definition given an existing interface file.
 */
static classDef *findClassWithInterface(sipSpec *pt, ifaceFileDef *iff)
{
    classDef *cd;

    for (cd = pt -> classes; cd != NULL; cd = cd -> next)
        if (cd -> iff == iff)
            return cd;

    /* Create a new one. */
    cd = sipMalloc(sizeof (classDef));

    cd->iff = iff;
    cd->pyname = cacheName(pt, classBaseName(cd));
    cd->next = pt->classes;

    pt->classes = cd;

    return cd;
}


/*
 * Add an interface file to an interface file list if it isn't already there.
 */
void appendToIfaceFileList(ifaceFileList **ifflp, ifaceFileDef *iff)
{
    /* Make sure we don't try to add an interface file to its own list. */
    if (&iff->used != ifflp)
    {
        ifaceFileList *iffl;

        while ((iffl = *ifflp) != NULL)
        {
            /* Don't bother if it is already there. */
            if (iffl->iff == iff)
                return;

            ifflp = &iffl -> next;
        }

        iffl = sipMalloc(sizeof (ifaceFileList));

        iffl->iff = iff;
        iffl->next = NULL;

        *ifflp = iffl;
    }
}


/*
 * Find an undefined (or create a new) exception definition in a parse tree.
 */
static exceptionDef *findException(sipSpec *pt, scopedNameDef *fqname, int new)
{
    exceptionDef *xd, **tail;
    ifaceFileDef *iff;
    classDef *cd;

    iff = findIfaceFile(pt, currentModule, fqname, exception_iface, NULL, NULL);

    /* See if it is an existing one. */
    for (xd = pt->exceptions; xd != NULL; xd = xd->next)
        if (xd->iff == iff)
            return xd;

    /*
     * If it is an exception interface file then we have never seen this name
     * before.  We require that exceptions are defined before being used, but
     * don't make the same requirement of classes (for reasons of backwards
     * compatibility).  Therefore the name must be reinterpreted as a (as yet
     * undefined) class.
     */
    if (new)
    {
        if (iff->type == exception_iface)
            cd = NULL;
        else
            yyerror("There is already a class with the same name or the exception has been used before being defined");
    }
    else
    {
        if (iff->type == exception_iface)
            iff->type = class_iface;

        cd = findClassWithInterface(pt, iff);
    }

    /* Create a new one. */
    xd = sipMalloc(sizeof (exceptionDef));

    xd->exceptionnr = -1;
    xd->iff = iff;
    xd->pyname = NULL;
    xd->cd = cd;
    xd->bibase = NULL;
    xd->base = NULL;
    xd->raisecode = NULL;
    xd->next = NULL;

    /* Append it to the list. */
    for (tail = &pt->exceptions; *tail != NULL; tail = &(*tail)->next)
        ;

    *tail = xd;

    return xd;
}


/*
 * Find an undefined (or create a new) class definition in a parse tree.
 */
static classDef *newClass(sipSpec *pt, ifaceFileType iftype,
        apiVersionRangeDef *api_range, scopedNameDef *fqname,
        const char *virt_error_handler, typeHintDef *typehint_in,
        typeHintDef *typehint_out, const char *typehint_value)
{
    int flags;
    classDef *cd, *scope;
    codeBlockList *hdrcode;

    if (sectionFlags & SECT_IS_PRIVATE)
        yyerror("Classes, structs and namespaces must be in the public or protected sections");

    flags = 0;

    if ((scope = currentScope()) != NULL)
    {
        if (sectionFlags & SECT_IS_PROT && !makeProtPublic)
        {
            flags = CLASS_IS_PROTECTED;

            if (scope->iff->type == class_iface)
                setHasShadow(scope);
        }

        /* Header code from outer scopes is also included. */
        hdrcode = scope->iff->hdrcode;
    }
    else
        hdrcode = NULL;

    if (pt -> genc)
    {
        /* C structs are always global types. */
        while (fqname -> next != NULL)
            fqname = fqname -> next;

        scope = NULL;
    }

    cd = findClass(pt, iftype, api_range, fqname);

    /* Check it hasn't already been defined. */
    if (iftype != namespace_iface && cd->iff->module != NULL)
        yyerror("The struct/class has already been defined");

    /* Complete the initialisation. */
    cd->classflags |= flags;
    cd->ecd = scope;
    cd->iff->module = currentModule;
    cd->virt_error_handler = virt_error_handler;
    cd->typehint_in = typehint_in;
    cd->typehint_out = typehint_out;
    cd->typehint_value = typehint_value;

    if (currentIsTemplate)
        setIsTemplateClass(cd);

    appendCodeBlockList(&cd->iff->hdrcode, hdrcode);

    /* See if it is a namespace extender. */
    if (iftype == namespace_iface)
    {
        classDef *ns;

        for (ns = pt->classes; ns != NULL; ns = ns->next)
        {
            if (ns == cd)
                continue;

            if (ns->iff->type != namespace_iface)
                continue;

            if (compareScopedNames(ns->iff->fqcname, fqname) != 0)
                continue;

            cd->real = ns;
            break;
        }
    }

    return cd;
}


/*
 * Tidy up after finishing a class definition.
 */
static void finishClass(sipSpec *pt, moduleDef *mod, classDef *cd,
        optFlags *of)
{
    const char *pyname;
    optFlag *flg;

    /* Get the Python name and see if it is different to the C++ name. */
    pyname = getPythonName(mod, of, classBaseName(cd));

    cd->pyname = NULL;
    checkAttributes(pt, mod, cd->ecd, NULL, pyname, FALSE);
    cd->pyname = cacheName(pt, pyname);
    cd->no_typehint = getNoTypeHint(of);

    if ((flg = getOptFlag(of, "Metatype", dotted_name_flag)) != NULL)
        cd->metatype = cacheName(pt, flg->fvalue.sval);

    if ((flg = getOptFlag(of, "Supertype", dotted_name_flag)) != NULL)
        cd->supertype = cacheName(pt, flg->fvalue.sval);

    if (getOptFlag(of, "ExportDerived", bool_flag) != NULL)
        setExportDerived(cd);

    if (getOptFlag(of, "Mixin", bool_flag) != NULL)
        setMixin(cd);

    if ((flg = getOptFlag(of, "FileExtension", string_flag)) != NULL)
        cd->iff->file_extension = flg->fvalue.sval;

    if ((flg = getOptFlag(of, "PyQtFlags", integer_flag)) != NULL)
        cd->pyqt_flags = flg->fvalue.ival;

    if (getOptFlag(of, "PyQtNoQMetaObject", bool_flag) != NULL)
        setPyQtNoQMetaObject(cd);

    if ((flg = getOptFlag(of, "PyQtInterface", string_flag)) != NULL)
        cd->pyqt_interface = flg->fvalue.sval;

    if (isOpaque(cd))
    {
        if (getOptFlag(of, "External", bool_flag) != NULL)
            setIsExternal(cd);
    }
    else
    {
        int seq_might, seq_not, default_to_sequence;
        memberDef *md;

        if (getOptFlag(of, "NoDefaultCtors", bool_flag) != NULL)
            setNoDefaultCtors(cd);

        if (cd -> ctors == NULL)
        {
            if (!noDefaultCtors(cd))
            {
                /* Provide a default ctor. */

                cd->ctors = sipMalloc(sizeof (ctorDef));
 
                cd->ctors->ctorflags = SECT_IS_PUBLIC;
                cd->ctors->pysig.result.atype = void_type;
                cd->ctors->cppsig = &cd->ctors->pysig;

                cd->defctor = cd->ctors;

                setCanCreate(cd);
            }
        }
        else if (cd -> defctor == NULL)
        {
            ctorDef *ct, *last = NULL;

            for (ct = cd -> ctors; ct != NULL; ct = ct -> next)
            {
                if (!isPublicCtor(ct))
                    continue;

                if (ct -> pysig.nrArgs == 0 || ct -> pysig.args[0].defval != NULL)
                {
                    cd -> defctor = ct;
                    break;
                }

                if (last == NULL)
                    last = ct;
            }

            /* The last resort is the first public ctor. */
            if (cd->defctor == NULL)
                cd->defctor = last;
        }

        if (getDeprecated(of))
            setIsDeprecatedClass(cd);

        if (cd->convtocode != NULL && getAllowNone(of))
            setClassHandlesNone(cd);

        if (getOptFlag(of,"Abstract",bool_flag) != NULL)
        {
            setIsAbstractClass(cd);
            setIsIncomplete(cd);
            resetCanCreate(cd);
        }

        /* We assume a public dtor if nothing specific was provided. */
        if (!isDtor(cd))
            setIsPublicDtor(cd);

        if (getOptFlag(of, "DelayDtor", bool_flag) != NULL)
        {
            setIsDelayedDtor(cd);
            setHasDelayedDtors(mod);
        }

        /*
         * There are subtle differences between the add and concat methods and
         * the multiply and repeat methods.  The number versions can have their
         * operands swapped and may return NotImplemented.  If the user has
         * used the /Numeric/ annotation or there are other numeric operators
         * then we use add/multiply.  Otherwise, if the user has used the
         * /Sequence/ annotation or there are indexing operators then we use
         * concat/repeat.
         */
        seq_might = seq_not = FALSE;

        for (md = cd->members; md != NULL; md = md->next)
            switch (md->slot)
            {
            case getitem_slot:
            case setitem_slot:
            case delitem_slot:
                /* This might be a sequence. */
                seq_might = TRUE;
                break;

            case sub_slot:
            case isub_slot:
            case div_slot:
            case idiv_slot:
            case mod_slot:
            case imod_slot:
            case floordiv_slot:
            case ifloordiv_slot:
            case truediv_slot:
            case itruediv_slot:
            case pos_slot:
            case neg_slot:
                /* This is definately not a sequence. */
                seq_not = TRUE;
                break;

            /* Suppress a compiler warning. */
            default:
                ;
            }

        default_to_sequence = (!seq_not && seq_might);

        for (md = cd->members; md != NULL; md = md->next)
        {
            /* Ignore if it is explicitly numeric. */
            if (isNumeric(md))
                continue;

            if (isSequence(md) || default_to_sequence)
                switch (md->slot)
                {
                case add_slot:
                    md->slot = concat_slot;
                    break;

                case iadd_slot:
                    md->slot = iconcat_slot;
                    break;

                case mul_slot:
                    md->slot = repeat_slot;
                    break;

                case imul_slot:
                    md->slot = irepeat_slot;
                    break;

                /* Suppress a compiler warning. */
                default:
                    ;
                }
        }
    }

    if (inMainModule())
    {
        setIsUsedName(cd->iff->name);
        setIsUsedName(cd->pyname);
    }
}


/*
 * Return the encoded name of a template (ie. including its argument types) as
 * a scoped name.
 */
scopedNameDef *encodedTemplateName(templateDef *td)
{
    int a;
    scopedNameDef *snd;

    snd = copyScopedName(td->fqname);

    for (a = 0; a < td->types.nrArgs; ++a)
    {
        char buf[50];
        int flgs;
        scopedNameDef *arg_snd;
        argDef *ad = &td->types.args[a];

        flgs = 0;

        if (isConstArg(ad))
            flgs += 1;

        if (isReference(ad))
            flgs += 2;

        /* We use numbers so they don't conflict with names. */
        sprintf(buf, "%02d%d%d", ad->atype, flgs, ad->nrderefs);

        switch (ad->atype)
        {
        case defined_type:
            arg_snd = copyScopedName(ad->u.snd);
            break;

        case template_type:
            arg_snd = encodedTemplateName(ad->u.td);
            break;

        case struct_type:
            arg_snd = copyScopedName(ad->u.sname);
            break;

        default:
            arg_snd = NULL;
        }

        /*
         * Replace the first element of the argument name with a copy with the
         * encoding prepended.
         */
        if (arg_snd != NULL)
            arg_snd->name = concat(buf, arg_snd->name, NULL);
        else
            arg_snd = text2scopePart(sipStrdup(buf));

        appendScopedName(&snd, arg_snd);
    }

    return snd;
}


/*
 * Create a new mapped type.
 */
static mappedTypeDef *newMappedType(sipSpec *pt, argDef *ad, optFlags *of)
{
    mappedTypeDef *mtd;
    scopedNameDef *snd;
    ifaceFileDef *iff;
    const char *cname;

    /* Check that the type is one we want to map. */
    switch (ad->atype)
    {
    case defined_type:
        snd = ad->u.snd;
        cname = scopedNameTail(snd);
        break;

    case template_type:
        snd = encodedTemplateName(ad->u.td);
        cname = NULL;
        break;

    case struct_type:
        snd = ad->u.sname;
        cname = scopedNameTail(snd);
        break;

    default:
        yyerror("Invalid type for %MappedType");
    }

    iff = findIfaceFile(pt, currentModule, snd, mappedtype_iface,
            getAPIRange(of), ad);

    /* Check it hasn't already been defined. */
    for (mtd = pt->mappedtypes; mtd != NULL; mtd = mtd->next)
        if (mtd->iff == iff)
        {
            /*
             * We allow types based on the same template but with different
             * arguments.
             */
            if (ad->atype != template_type || sameBaseType(ad, &mtd->type))
                yyerror("Mapped type has already been defined in this module");
        }

    /* The module may not have been set yet. */
    iff->module = currentModule;

    /* Create a new mapped type. */
    mtd = allocMappedType(pt, ad);

    if (cname != NULL)
        mtd->pyname = cacheName(pt, getPythonName(currentModule, of, cname));

    mappedTypeAnnos(mtd, of);

    mtd->iff = iff;
    mtd->next = pt->mappedtypes;

    pt->mappedtypes = mtd;

    if (inMainModule())
    {
        setIsUsedName(mtd->cname);

        if (mtd->pyname)
            setIsUsedName(mtd->pyname);
    }

    return mtd;
}


/*
 * Allocate, initialise and return a mapped type structure.
 */
mappedTypeDef *allocMappedType(sipSpec *pt, argDef *type)
{
    mappedTypeDef *mtd;

    mtd = sipMalloc(sizeof (mappedTypeDef));

    mtd->type = *type;
    mtd->type.argflags = 0;
    mtd->type.nrderefs = 0;

    mtd->cname = cacheName(pt, type2string(&mtd->type));

    return mtd;
}


/*
 * Create a new enum.
 */
static enumDef *newEnum(sipSpec *pt, moduleDef *mod, mappedTypeDef *mt_scope,
        char *name, optFlags *of, int flags)
{
    enumDef *ed, *first_alt, *next_alt;
    classDef *c_scope;
    ifaceFileDef *scope;

    if (mt_scope != NULL)
    {
        scope = mt_scope->iff;
        c_scope = NULL;
    }
    else
    {
        if ((c_scope = currentScope()) != NULL)
            scope = c_scope->iff;
        else
            scope = NULL;
    }

    ed = sipMalloc(sizeof (enumDef));

    /* Assume the enum isn't versioned. */
    first_alt = ed;
    next_alt = NULL;

    if (name != NULL)
    {
        ed->pyname = cacheName(pt, getPythonName(mod, of, name));
        checkAttributes(pt, mod, c_scope, mt_scope, ed->pyname->text, FALSE);

        ed->fqcname = text2scopedName(scope, name);
        ed->cname = cacheName(pt, scopedNameToString(ed->fqcname));

        if (inMainModule())
        {
            setIsUsedName(ed->pyname);
            setIsUsedName(ed->cname);
        }

        /* If the scope is versioned then look for any alternate. */
        if (scope != NULL && scope->api_range != NULL)
        {
            enumDef *alt;

            for (alt = pt->enums; alt != NULL; alt = alt->next)
            {
                if (alt->module != mod || alt->fqcname == NULL)
                    continue;

                if (compareScopedNames(alt->fqcname, ed->fqcname) == 0)
                {
                    first_alt = alt->first_alt;
                    next_alt = first_alt->next_alt;
                    first_alt->next_alt = ed;

                    break;
                }
            }
        }
    }
    else
    {
        ed->pyname = NULL;
        ed->fqcname = NULL;
        ed->cname = NULL;
    }

    if (flags & SECT_IS_PROT)
    {
        if (makeProtPublic)
        {
            flags &= ~SECT_IS_PROT;
            flags |= SECT_IS_PUBLIC;
        }
        else if (c_scope != NULL)
        {
            setHasShadow(c_scope);
        }
    }

    ed->enumflags = flags;
    ed->no_typehint = getNoTypeHint(of);
    ed->enumnr = -1;
    ed->ecd = c_scope;
    ed->emtd = mt_scope;
    ed->first_alt = first_alt;
    ed->next_alt = next_alt;
    ed->module = mod;
    ed->members = NULL;
    ed->slots = NULL;
    ed->overs = NULL;
    ed->next = pt -> enums;

    pt->enums = ed;

    if (getOptFlag(of, "NoScope", bool_flag) != NULL)
        setIsNoScope(ed);

    return ed;
}


/*
 * Get the type values and (optionally) the type names for substitution in
 * handwritten code.
 */
void appendTypeStrings(scopedNameDef *ename, signatureDef *patt, signatureDef *src, signatureDef *known, scopedNameDef **names, scopedNameDef **values)
{
    int a;

    for (a = 0; a < patt->nrArgs; ++a)
    {
        argDef *pad = &patt->args[a];

        if (pad->atype == defined_type)
        {
            char *nam = NULL, *val;
            argDef *sad;

            /*
             * If the type names are already known then check that this is one
             * of them.
             */
            if (known == NULL)
                nam = scopedNameTail(pad->u.snd);
            else if (pad->u.snd->next == NULL)
            {
                int k;

                for (k = 0; k < known->nrArgs; ++k)
                {
                    /* Skip base types. */
                    if (known->args[k].atype != defined_type)
                        continue;

                    if (strcmp(pad->u.snd->name, known->args[k].u.snd->name) == 0)
                    {
                        nam = pad->u.snd->name;
                        break;
                    }
                }
            }

            if (nam == NULL)
                continue;

            /* Add the name. */
            appendScopedName(names, text2scopePart(nam));

            /*
             * Add the corresponding value.  For defined types we don't want 
             * any indirection or references.
             */
            sad = &src->args[a];

            if (sad->atype == defined_type)
                val = scopedNameToString(sad->u.snd);
            else
                val = type2string(sad);

            /* We do want const. */
            if (isConstArg(sad))
            {
                char *const_val = sipStrdup("const ");

                append(&const_val, val);
                free(val);

                val = const_val;
            }

            appendScopedName(values, text2scopePart(val));
        }
        else if (pad->atype == template_type)
        {
            argDef *sad = &src->args[a];

            /* These checks shouldn't be necessary, but... */
            if (sad->atype == template_type && pad->u.td->types.nrArgs == sad->u.td->types.nrArgs)
                appendTypeStrings(ename, &pad->u.td->types, &sad->u.td->types, known, names, values);
        }
    }
}


/*
 * Convert a type to a string on the heap.  The string will use the minimum
 * whitespace while still remaining valid C++.
 */
static char *type2string(argDef *ad)
{
    int i, on_heap = FALSE;
    int nr_derefs = ad->nrderefs;
    int is_reference = isReference(ad);
    char *s;

    /* Use the original type if possible. */
    if (ad->original_type != NULL && !noTypeName(ad->original_type))
    {
        s = scopedNameToString(ad->original_type->fqname);
        on_heap = TRUE;

        nr_derefs -= ad->original_type->type.nrderefs;

        if (isReference(&ad->original_type->type))
            is_reference = FALSE;
    }
    else
        switch (ad->atype)
        {
        case template_type:
            {
                templateDef *td = ad->u.td;

                s = scopedNameToString(td->fqname);
                append(&s, "<");

                for (i = 0; i < td->types.nrArgs; ++i)
                {
                    char *sub_type = type2string(&td->types.args[i]);

                    if (i > 0)
                        append(&s, ",");

                    append(&s, sub_type);
                    free(sub_type);
                }

                if (s[strlen(s) - 1] == '>')
                    append(&s, " >");
                else
                    append(&s, ">");

                on_heap = TRUE;
                break;
            }

        case struct_type:
            s = scopedNameToString(ad->u.sname);
            on_heap = TRUE;
            break;

        case defined_type:
            s = scopedNameToString(ad->u.snd);
            on_heap = TRUE;
            break;

        case ubyte_type:
        case ustring_type:
            s = "unsigned char";
            break;

        case byte_type:
        case ascii_string_type:
        case latin1_string_type:
        case utf8_string_type:
        case string_type:
            s = "char";
            break;

        case sbyte_type:
        case sstring_type:
            s = "signed char";
            break;

        case wstring_type:
            s = "wchar_t";
            break;

        case ushort_type:
            s = "unsigned short";
            break;

        case short_type:
            s = "short";
            break;

        case uint_type:
            s = "uint";
            break;

        case int_type:
        case cint_type:
            s = "int";
            break;

        case ulong_type:
            s = "unsigned long";
            break;

        case long_type:
            s = "long";
            break;

        case ulonglong_type:
            s = "unsigned long long";
            break;

        case longlong_type:
            s = "long long";
            break;

        case float_type:
        case cfloat_type:
            s = "float";
            break;

        case double_type:
        case cdouble_type:
            s = "double";
            break;

        case bool_type:
        case cbool_type:
            s = "bool";
            break;

        case void_type:
            s = "void";
            break;

        case capsule_type:
            s = "void *";
            break;

        default:
            fatal("Unsupported type argument to type2string(): %d\n", ad->atype);
        }

    /* Make sure the string is on the heap. */
    if (!on_heap)
        s = sipStrdup(s);

    while (nr_derefs-- > 0)
        append(&s, "*");

    if (is_reference)
        append(&s, "&");

    return s;
}


/*
 * Convert a scoped name to a string on the heap.
 */
static char *scopedNameToString(scopedNameDef *name)
{
    static const char scope_string[] = "::";
    size_t len;
    scopedNameDef *snd;
    char *s, *dp;

    /* Work out the length of buffer needed. */
    len = 0;

    for (snd = name; snd != NULL; snd = snd->next)
    {
        len += strlen(snd->name);

        if (snd->next != NULL)
        {
            /* Ignore the encoded part of template names. */
            if (isdigit(snd->next->name[0]))
                break;

            len += strlen(scope_string);
        }
    }

    /* Allocate and populate the buffer. */
    dp = s = sipMalloc(len + 1);

    for (snd = name; snd != NULL; snd = snd->next)
    {
        strcpy(dp, snd->name);
        dp += strlen(snd->name);

        if (snd->next != NULL)
        {
            /* Ignore the encoded part of template names. */
            if (isdigit(snd->next->name[0]))
                break;

            strcpy(dp, scope_string);
            dp += strlen(scope_string);
        }
    }

    return s;
}


/*
 * Instantiate a class template.
 */
static void instantiateClassTemplate(sipSpec *pt, moduleDef *mod,
        classDef *scope, scopedNameDef *fqname, classTmplDef *tcd,
        templateDef *td, const char *pyname)
{
    scopedNameDef *type_names, *type_values;
    classDef *cd;
    ctorDef *oct, **cttail;
    argDef *ad;
    ifaceFileList *iffl, **used;
    classList *cl;

    type_names = type_values = NULL;
    appendTypeStrings(classFQCName(tcd->cd), &tcd->sig, &td->types, NULL, &type_names, &type_values);

    /*
     * Add a mapping from the template name to the instantiated name.  If we
     * have got this far we know there is room for it.
     */
    ad = &tcd->sig.args[tcd->sig.nrArgs++];
    memset(ad, 0, sizeof (argDef));
    ad->atype = defined_type;
    ad->u.snd = classFQCName(tcd->cd);

    appendScopedName(&type_names, text2scopePart(scopedNameTail(classFQCName(tcd->cd))));
    appendScopedName(&type_values, text2scopePart(scopedNameToString(fqname)));

    /* Create the new class. */
    cd = sipMalloc(sizeof (classDef));

    /* Start with a shallow copy. */
    *cd = *tcd->cd;

    resetIsTemplateClass(cd);
    cd->pyname = cacheName(pt, pyname);
    cd->td = td;

    /* Handle the interface file. */
    cd->iff = findIfaceFile(pt, mod, fqname, class_iface,
            (scope != NULL ? scope->iff->api_range : NULL), NULL);
    cd->iff->module = mod;

    appendCodeBlockList(&cd->iff->hdrcode, tcd->cd->iff->hdrcode);

    /* Make a copy of the used list and add the enclosing scope. */
    used = &cd->iff->used;

    for (iffl = tcd->cd->iff->used; iffl != NULL; iffl = iffl->next)
        appendToIfaceFileList(used, iffl->iff);

    /* Include any scope header code. */
    if (scope != NULL)
        appendCodeBlockList(&cd->iff->hdrcode, scope->iff->hdrcode);

    if (inMainModule())
    {
        setIsUsedName(cd->iff->name);
        setIsUsedName(cd->pyname);
    }

    cd->ecd = currentScope();

    /* Handle any type hints. */
    if (cd->typehint_in != NULL)
        cd->typehint_in = newTypeHint(
                templateString(cd->typehint_in->raw_hint, type_names,
                        type_values));

    if (cd->typehint_out != NULL)
        cd->typehint_out = newTypeHint(
                templateString(cd->typehint_out->raw_hint, type_names,
                        type_values));

    /* Handle the super-classes. */
    for (cl = cd->supers; cl != NULL; cl = cl->next)
    {
        const char *name;
        int a;

        /* Ignore defined or scoped classes. */
        if (cl->cd->iff->module != NULL || cl->cd->iff->fqcname->next != NULL)
            continue;

        name = cl->cd->iff->fqcname->name;

        for (a = 0; a < tcd->sig.nrArgs - 1; ++a)
            if (strcmp(name, scopedNameTail(tcd->sig.args[a].u.snd)) == 0)
            {
                argDef *tad = &td->types.args[a];
                classDef *icd;

                if (tad->atype == defined_type)
                    icd = findClass(pt, class_iface, NULL, tad->u.snd);
                else if (tad->atype == class_type)
                    icd = tad->u.cd;
                else
                    fatal("Template argument %s must expand to a class\n", name);

                /*
                 * Don't complain about the template argument being undefined.
                 */
                setTemplateArg(cl->cd);

                cl->cd = icd;
            }
    }

    /* Handle the enums. */
    instantiateTemplateEnums(pt, tcd, td, cd, used, type_names, type_values);

    /* Handle the variables. */
    instantiateTemplateVars(pt, tcd, td, cd, used, type_names, type_values);

    /* Handle the typedefs. */
    instantiateTemplateTypedefs(pt, tcd, td, cd, type_names, type_values);

    /* Handle the ctors. */
    cd->ctors = NULL;
    cttail = &cd->ctors;

    for (oct = tcd->cd->ctors; oct != NULL; oct = oct->next)
    {
        ctorDef *nct = sipMalloc(sizeof (ctorDef));

        /* Start with a shallow copy. */
        *nct = *oct;

        templateSignature(&nct->pysig, FALSE, tcd, td, cd, type_names,
                type_values);

        if (oct->cppsig == NULL)
            nct->cppsig = NULL;
        else if (oct->cppsig == &oct->pysig)
            nct->cppsig = &nct->pysig;
        else
        {
            nct->cppsig = sipMalloc(sizeof (signatureDef));

            *nct->cppsig = *oct->cppsig;

            templateSignature(nct->cppsig, FALSE, tcd, td, cd, type_names,
                    type_values);
        }

        nct->methodcode = templateCode(pt, used, nct->methodcode, type_names, type_values);

        nct->next = NULL;
        *cttail = nct;
        cttail = &nct->next;

        /* Handle the default ctor. */
        if (tcd->cd->defctor == oct)
            cd->defctor = nct;
    }

    cd->dealloccode = templateCode(pt, used, cd->dealloccode, type_names, type_values);
    cd->dtorcode = templateCode(pt, used, cd->dtorcode, type_names, type_values);

    /* Handle the methods. */
    cd->members = instantiateTemplateMethods(tcd->cd->members, mod);
    cd->overs = instantiateTemplateOverloads(pt, tcd->cd->overs,
            tcd->cd->members, cd->members, tcd, td, cd, used, type_names,
            type_values);

    cd->cppcode = templateCode(pt, used, cd->cppcode, type_names, type_values);
    cd->iff->hdrcode = templateCode(pt, used, cd->iff->hdrcode, type_names, type_values);
    cd->convtosubcode = templateCode(pt, used, cd->convtosubcode, type_names, type_values);
    cd->convtocode = templateCode(pt, used, cd->convtocode, type_names, type_values);
    cd->travcode = templateCode(pt, used, cd->travcode, type_names, type_values);
    cd->clearcode = templateCode(pt, used, cd->clearcode, type_names, type_values);
    cd->getbufcode = templateCode(pt, used, cd->getbufcode, type_names, type_values);
    cd->releasebufcode = templateCode(pt, used, cd->releasebufcode, type_names, type_values);
    cd->readbufcode = templateCode(pt, used, cd->readbufcode, type_names, type_values);
    cd->writebufcode = templateCode(pt, used, cd->writebufcode, type_names, type_values);
    cd->segcountcode = templateCode(pt, used, cd->segcountcode, type_names, type_values);
    cd->charbufcode = templateCode(pt, used, cd->charbufcode, type_names, type_values);
    cd->instancecode = templateCode(pt, used, cd->instancecode, type_names, type_values);
    cd->picklecode = templateCode(pt, used, cd->picklecode, type_names, type_values);
    cd->finalcode = templateCode(pt, used, cd->finalcode, type_names, type_values);
    cd->typehintcode = templateCode(pt, used, cd->typehintcode, type_names, type_values);
    cd->next = pt->classes;

    pt->classes = cd;

    tcd->sig.nrArgs--;

    freeScopedName(type_names);
    freeScopedName(type_values);
}


/*
 * Instantiate the methods of a template class.
 */
static memberDef *instantiateTemplateMethods(memberDef *tmd, moduleDef *mod)
{
    memberDef *md, *methods, **mdtail;

    methods = NULL;
    mdtail = &methods;

    for (md = tmd; md != NULL; md = md->next)
    {
        memberDef *nmd = sipMalloc(sizeof (memberDef));

        /* Start with a shallow copy. */
        *nmd = *md;

        nmd->module = mod;

        if (inMainModule())
            setIsUsedName(nmd->pyname);

        nmd->next = NULL;
        *mdtail = nmd;
        mdtail = &nmd->next;
    }

    return methods;
}


/*
 * Instantiate the overloads of a template class.
 */
static overDef *instantiateTemplateOverloads(sipSpec *pt, overDef *tod,
        memberDef *tmethods, memberDef *methods, classTmplDef *tcd,
        templateDef *td, classDef *cd, ifaceFileList **used,
        scopedNameDef *type_names, scopedNameDef *type_values)
{
    overDef *od, *overloads, **odtail;

    overloads = NULL;
    odtail = &overloads;

    for (od = tod; od != NULL; od = od->next)
    {
        overDef *nod = sipMalloc(sizeof (overDef));
        memberDef *nmd, *omd;

        /* Start with a shallow copy. */
        *nod = *od;

        for (nmd = methods, omd = tmethods; omd != NULL; omd = omd->next, nmd = nmd->next)
            if (omd == od->common)
            {
                nod->common = nmd;
                break;
            }

        templateSignature(&nod->pysig, TRUE, tcd, td, cd, type_names,
                type_values);

        if (od->cppsig == &od->pysig)
            nod->cppsig = &nod->pysig;
        else
        {
            nod->cppsig = sipMalloc(sizeof (signatureDef));

            *nod->cppsig = *od->cppsig;

            templateSignature(nod->cppsig, TRUE, tcd, td, cd, type_names,
                    type_values);
        }

        nod->methodcode = templateCode(pt, used, nod->methodcode, type_names, type_values);
        nod->virtcallcode = templateCode(pt, used, nod->virtcallcode, type_names, type_values);

        /* Handle any virtual handler. */
        if (od->virthandler != NULL)
        {
            moduleDef *mod = cd->iff->module;

            nod->virthandler = sipMalloc(sizeof (virtHandlerDef));

            /* Start with a shallow copy. */
            *nod->virthandler = *od->virthandler;

            nod->virthandler->pysig = &nod->pysig;
            nod->virthandler->cppsig = nod->cppsig;

            nod->virthandler->module = mod;
            nod->virthandler->virtcode = templateCode(pt, used, nod->virthandler->virtcode, type_names, type_values);
            nod->virthandler->next = mod->virthandlers;

            mod->virthandlers = nod->virthandler;
        }

        nod->next = NULL;
        *odtail = nod;
        odtail = &nod->next;
    }

    return overloads;
}


/*
 * Instantiate the enums of a template class.
 */
static void instantiateTemplateEnums(sipSpec *pt, classTmplDef *tcd,
        templateDef *td, classDef *cd, ifaceFileList **used,
        scopedNameDef *type_names, scopedNameDef *type_values)
{
    enumDef *ted;
    moduleDef *mod = cd->iff->module;

    for (ted = pt->enums; ted != NULL; ted = ted->next)
        if (ted->ecd == tcd->cd)
        {
            enumDef *ed;
            enumMemberDef *temd;

            ed = sipMalloc(sizeof (enumDef));

            /* Start with a shallow copy. */
            *ed = *ted;

            if (ed->fqcname != NULL)
            {
                ed->fqcname = text2scopedName(cd->iff,
                        scopedNameTail(ed->fqcname));
                ed->cname = cacheName(pt, scopedNameToString(ed->fqcname));
            }

            if (inMainModule())
            {
                if (ed->pyname != NULL)
                    setIsUsedName(ed->pyname);

                if (ed->cname != NULL)
                    setIsUsedName(ed->cname);
            }

            ed->ecd = cd;
            ed->first_alt = ed;
            ed->module = mod;
            ed->members = NULL;

            for (temd = ted->members; temd != NULL; temd = temd->next)
            {
                enumMemberDef *emd;

                emd = sipMalloc(sizeof (enumMemberDef));

                /* Start with a shallow copy. */
                *emd = *temd;
                emd->ed = ed;

                emd->next = ed->members;
                ed->members = emd;
            }

            ed->slots = instantiateTemplateMethods(ted->slots, mod);
            ed->overs = instantiateTemplateOverloads(pt, ted->overs,
                    ted->slots, ed->slots, tcd, td, cd, used, type_names,
                    type_values);

            ed->next = pt->enums;
            pt->enums = ed;
        }
}


/*
 * Instantiate the variables of a template class.
 */
static void instantiateTemplateVars(sipSpec *pt, classTmplDef *tcd,
        templateDef *td, classDef *cd, ifaceFileList **used,
        scopedNameDef *type_names, scopedNameDef *type_values)
{
    varDef *tvd;

    for (tvd = pt->vars; tvd != NULL; tvd = tvd->next)
        if (tvd->ecd == tcd->cd)
        {
            varDef *vd;

            vd = sipMalloc(sizeof (varDef));

            /* Start with a shallow copy. */
            *vd = *tvd;

            if (inMainModule())
                setIsUsedName(vd->pyname);

            vd->fqcname = text2scopedName(cd->iff,
                    scopedNameTail(vd->fqcname));
            vd->ecd = cd;
            vd->module = cd->iff->module;

            templateType(&vd->type, tcd, td, cd, type_names, type_values);

            vd->accessfunc = templateCode(pt, used, vd->accessfunc, type_names, type_values);
            vd->getcode = templateCode(pt, used, vd->getcode, type_names, type_values);
            vd->setcode = templateCode(pt, used, vd->setcode, type_names, type_values);

            addVariable(pt, vd);
        }
}


/*
 * Instantiate the typedefs of a template class.
 */
static void instantiateTemplateTypedefs(sipSpec *pt, classTmplDef *tcd,
        templateDef *td, classDef *cd, scopedNameDef *type_names,
        scopedNameDef *type_values)
{
    typedefDef *tdd;

    for (tdd = pt->typedefs; tdd != NULL; tdd = tdd->next)
    {
        typedefDef *new_tdd;

        if (tdd->ecd != tcd->cd)
            continue;

        new_tdd = sipMalloc(sizeof (typedefDef));

        /* Start with a shallow copy. */
        *new_tdd = *tdd;

        new_tdd->fqname = text2scopedName(cd->iff,
                scopedNameTail(new_tdd->fqname));
        new_tdd->ecd = cd;
        new_tdd->module = cd->iff->module;

        templateType(&new_tdd->type, tcd, td, cd, type_names, type_values);

        addTypedef(pt, new_tdd);
    }
}


/*
 * Replace any template arguments in a signature.
 */
static void templateSignature(signatureDef *sd, int result, classTmplDef *tcd,
        templateDef *td, classDef *ncd, scopedNameDef *type_names,
        scopedNameDef *type_values)
{
    int a;

    if (result)
        templateType(&sd->result, tcd, td, ncd, type_names, type_values);

    for (a = 0; a < sd->nrArgs; ++a)
        templateType(&sd->args[a], tcd, td, ncd, type_names, type_values);
}


/*
 * Replace any template arguments in a type.
 */
static void templateType(argDef *ad, classTmplDef *tcd, templateDef *td,
        classDef *ncd, scopedNameDef *type_names, scopedNameDef *type_values)
{
    int a;
    char *name;

    /* Descend into any sub-templates. */
    if (ad->atype == template_type)
    {
        templateDef *new_td = sipMalloc(sizeof (templateDef));

        /* Make a deep copy of the template definition. */
        *new_td = *ad->u.td;
        ad->u.td = new_td;

        templateSignature(&ad->u.td->types, FALSE, tcd, td, ncd, type_names,
                type_values);

        return;
    }

    /* Handle any type hints. */
    if (ad->typehint_in != NULL)
        ad->typehint_in = newTypeHint(
                templateString(ad->typehint_in->raw_hint, type_names,
                        type_values));

    if (ad->typehint_out != NULL)
        ad->typehint_out = newTypeHint(
                templateString(ad->typehint_out->raw_hint, type_names,
                        type_values));

    /* Ignore if it isn't an unscoped name. */
    if (ad->atype != defined_type || ad->u.snd->next != NULL)
        return;

    name = ad->u.snd->name;

    for (a = 0; a < tcd->sig.nrArgs - 1; ++a)
        if (strcmp(name, scopedNameTail(tcd->sig.args[a].u.snd)) == 0)
        {
            argDef *tad = &td->types.args[a];

            ad->atype = tad->atype;

            /* We take the constrained flag from the real type. */
            resetIsConstrained(ad);

            if (isConstrained(tad))
                setIsConstrained(ad);

            ad->u = tad->u;

            return;
        }

    /* Handle the class name itself. */
    if (strcmp(name, scopedNameTail(classFQCName(tcd->cd))) == 0)
    {
        ad->atype = class_type;
        ad->u.cd = ncd;
        ad->original_type = NULL;
    }
}


/*
 * Replace any template arguments in a literal code block.
 */
codeBlockList *templateCode(sipSpec *pt, ifaceFileList **used,
        codeBlockList *ocbl, scopedNameDef *names, scopedNameDef *values)
{
    codeBlockList *ncbl = NULL;

    while (ocbl != NULL)
    {
        char *at = ocbl->block->frag;
        int start_of_line = TRUE;

        do
        {
            char *from = at, *first = NULL;
            codeBlock *cb;
            scopedNameDef *nam, *val, *nam_first, *val_first;

            /* Suppress a compiler warning. */
            val_first = NULL;

            /*
             * Don't do any substitution in lines that appear to be
             * preprocessor directives.  This prevents #include'd file names
             * being broken.
             */
            if (start_of_line)
            {
                /* Strip leading whitespace. */
                while (isspace(*from))
                    ++from;

                if (*from == '#')
                {
                    /* Skip to the end of the line. */
                    do
                        ++from;
                    while (*from != '\n' && *from != '\0');
                }
                else
                {
                    start_of_line = FALSE;
                }
            }

            /*
             * Go through the rest of this fragment looking for each of the
             * types and the name of the class itself.
             */
            nam = names;
            val = values;

            while (nam != NULL && val != NULL)
            {
                char *cp;

                if ((cp = strstr(from, nam->name)) != NULL)
                    if (first == NULL || first > cp)
                    {
                        nam_first = nam;
                        val_first = val;
                        first = cp;
                    }

                nam = nam->next;
                val = val->next;
            }

            /* Create the new fragment. */
            cb = sipMalloc(sizeof (codeBlock));

            if (at == ocbl->block->frag)
            {
                cb->filename = ocbl->block->filename;
                cb->linenr = ocbl->block->linenr;
            }
            else
                cb->filename = NULL;

            appendCodeBlock(&ncbl, cb);

            /* See if anything was found. */
            if (first == NULL)
            {
                /* We can just point to this. */
                cb->frag = at;

                /* All done with this one. */
                at = NULL;
            }
            else
            {
                static char *gen_names[] = {
                    "sipType_",
                    "sipClass_",
                    "sipEnum_",
                    "sipException_",
                    NULL
                };

                char *dp, *sp, **gn;
                int genname = FALSE;

                /*
                 * If the context in which the text is used is in the name of a
                 * SIP generated object then translate any "::" scoping to "_"
                 * and remove any const.
                 */
                for (gn = gen_names; *gn != NULL; ++gn)
                    if (search_back(first, at, *gn))
                    {
                        addUsedFromCode(pt, used, val_first->name);
                        genname = TRUE;
                        break;
                    }

                /* Fragment the fragment. */
                cb->frag = sipMalloc(first - at + strlen(val_first->name) + 1);

                strncpy(cb->frag, at, first - at);

                dp = &cb->frag[first - at];
                sp = val_first->name;

                if (genname)
                {
                    char gch;

                    if (strlen(sp) > 6 && strncmp(sp, "const ", 6) == 0)
                        sp += 6;

                    while ((gch = *sp++) != '\0')
                        if (gch == ':' && *sp == ':')
                        {
                            *dp++ = '_';
                            ++sp;
                        }
                        else
                            *dp++ = gch;

                    *dp = '\0';
                }
                else
                    strcpy(dp, sp);

                /* Move past the replaced text. */
                at = first + strlen(nam_first->name);

                if (*at == '\n')
                    start_of_line = TRUE;
            }
        }
        while (at != NULL && *at != '\0');

        ocbl = ocbl->next;
    }

    return ncbl;
}


/*
 * Return TRUE if the text at the end of a string matches the target string.
 */
static int search_back(const char *end, const char *start, const char *target)
{
    size_t tlen = strlen(target);

    if (start + tlen >= end)
        return FALSE;

    return (strncmp(end - tlen, target, tlen) == 0);
}


/*
 * Add any needed interface files based on handwritten code.
 */
static void addUsedFromCode(sipSpec *pt, ifaceFileList **used, const char *sname)
{
    ifaceFileDef *iff;
    enumDef *ed;

    for (iff = pt->ifacefiles; iff != NULL; iff = iff->next)
    {
        if (iff->type != class_iface && iff->type != exception_iface)
            continue;

        if (sameName(iff->fqcname, sname))
        {
            appendToIfaceFileList(used, iff);
            return;
        }
    }

    for (ed = pt->enums; ed != NULL; ed = ed->next)
    {
        if (ed->ecd == NULL)
            continue;

        if (sameName(ed->fqcname, sname))
        {
            appendToIfaceFileList(used, ed->ecd->iff);
            return;
        }
    }
}


/*
 * Compare a scoped name with its string equivalent.
 */
static int sameName(scopedNameDef *snd, const char *sname)
{
    while (snd != NULL && *sname != '\0')
    {
        const char *sp = snd->name;

        while (*sp != '\0' && *sname != ':' && *sname != '\0')
            if (*sp++ != *sname++)
                return FALSE;

        if (*sp != '\0' || (*sname != ':' && *sname != '\0'))
            return FALSE;

        snd = snd->next;

        if (*sname == ':')
            sname += 2;
    }

    return (snd == NULL && *sname == '\0');
}


/*
 * Compare a (possibly) relative scoped name with a fully qualified scoped name
 * while taking the current scope into account.
 */
static int foundInScope(scopedNameDef *fq_name, scopedNameDef *rel_name)
{
    classDef *scope;

    for (scope = currentScope(); scope != NULL; scope = scope->ecd)
    {
        scopedNameDef *snd;
        int found;

        snd = copyScopedName(classFQCName(scope));
        appendScopedName(&snd, copyScopedName(rel_name));

        found = (compareScopedNames(fq_name, snd) == 0);

        freeScopedName(snd);

        if (found)
            return TRUE;
    }

    return compareScopedNames(fq_name, rel_name) == 0;
}


/*
 * Create a new typedef.
 */
static void newTypedef(sipSpec *pt, moduleDef *mod, char *name, argDef *type,
        optFlags *optflgs)
{
    typedefDef *td;
    scopedNameDef *fqname;
    classDef *scope;

    scope = currentScope();
    fqname = text2scopedName((scope != NULL ? scope->iff : NULL), name);

    /* See if we are instantiating a template class. */
    if (type->atype == template_type)
    {
        classTmplDef *tcd;
        templateDef *td = type->u.td;

        for (tcd = pt->classtemplates; tcd != NULL; tcd = tcd->next)
            if (foundInScope(tcd->cd->iff->fqcname, td->fqname) &&
                sameTemplateSignature(&tcd->sig, &td->types, FALSE))
            {
                instantiateClassTemplate(pt, mod, scope, fqname, tcd, td,
                        getPythonName(mod, optflgs, name));

                /* All done. */
                return;
            }
    }

    td = sipMalloc(sizeof (typedefDef));

    td->tdflags = 0;
    td->fqname = fqname;
    td->ecd = scope;
    td->module = mod;
    td->type = *type;

    if (getOptFlag(optflgs, "Capsule", bool_flag) != NULL)
    {
        /* Make sure the type is void *. */
        if (type->atype != void_type || type->nrderefs != 1 || isConstArg(type) || isReference(type))
        {
            fatalScopedName(fqname);
            fatal(" must be a void* if /Capsule/ is specified\n");
        }

        td->type.atype = capsule_type;
        td->type.nrderefs = 0;
        td->type.u.cap = fqname;
    }

    if (getOptFlag(optflgs, "NoTypeName", bool_flag) != NULL)
        setNoTypeName(td);

    addTypedef(pt, td);
}


/*
 * Add a typedef to the list so that the list remains sorted.
 */
static void addTypedef(sipSpec *pt, typedefDef *tdd)
{
    typedefDef **tdp;

    /*
     * Check it doesn't already exist and find the position in the sorted list
     * where it should be put.
     */
    for (tdp = &pt->typedefs; *tdp != NULL; tdp = &(*tdp)->next)
    {
        int res = compareScopedNames((*tdp)->fqname, tdd->fqname);

        if (res == 0)
        {
            fatalScopedName(tdd->fqname);
            fatal(" already defined\n");
        }

        if (res > 0)
            break;
    }

    tdd->next = *tdp;
    *tdp = tdd;

    tdd->module->nrtypedefs++;
}


/*
 * Speculatively try and resolve any typedefs.  In some cases (eg. when
 * comparing template signatures) it helps to use the real type if it is known.
 * Note that this wouldn't be necessary if we required that all types be known
 * before they are used.
 */
static void resolveAnyTypedef(sipSpec *pt, argDef *ad)
{
    argDef orig = *ad;

    while (ad->atype == defined_type)
    {
        ad->atype = no_type;
        searchTypedefs(pt, ad->u.snd, ad);

        /*
         * Don't resolve to a template type as it may be superceded later on
         * by a more specific mapped type.
         */
        if (ad->atype == no_type || ad->atype == template_type)
        {
            *ad = orig;
            break;
        }
    }
}


/*
 * Return TRUE if the template signatures are the same.  A deep comparison is
 * used for mapped type templates where we want to recurse into any nested
 * templates.
 */
int sameTemplateSignature(signatureDef *tmpl_sd, signatureDef *args_sd,
        int deep)
{
    int a;

    if (tmpl_sd->nrArgs != args_sd->nrArgs)
        return FALSE;

    for (a = 0; a < tmpl_sd->nrArgs; ++a)
    {
        argDef *tmpl_ad = &tmpl_sd->args[a];
        argDef *args_ad = &args_sd->args[a];

        /*
         * If we are doing a shallow comparision (ie. for class templates) then
         * a type name in the template signature matches anything in the
         * argument signature.
         */
        if (tmpl_ad->atype == defined_type && !deep)
            continue;

        /*
         * For type names only compare the references and pointers, and do the
         * same for any nested templates.
         */
        if (tmpl_ad->atype == defined_type && args_ad->atype == defined_type)
        {
            if (isReference(tmpl_ad) != isReference(args_ad) || tmpl_ad->nrderefs != args_ad->nrderefs)
                return FALSE;
        }
        else if (tmpl_ad->atype == template_type && args_ad->atype == template_type)
        {
            if (!sameTemplateSignature(&tmpl_ad->u.td->types, &args_ad->u.td->types, deep))
                return FALSE;
        }
        else if (!sameBaseType(tmpl_ad, args_ad))
            return FALSE;
    }

    return TRUE;
}


/*
 * Create a new variable.
 */
static void newVar(sipSpec *pt, moduleDef *mod, char *name, int isstatic,
        argDef *type, optFlags *of, codeBlock *acode, codeBlock *gcode,
        codeBlock *scode, int section)
{
    varDef *var;
    classDef *escope = currentScope();
    nameDef *nd;

    /*
     * For the moment we don't support capsule variables because it needs the
     * API major version increasing.
     */
    if (type->atype == capsule_type)
        yyerror("Capsule variables not yet supported");

    /* Check the section. */
    if (section != 0)
    {
        if ((section & SECT_IS_PUBLIC) == 0)
            yyerror("Class variables must be in the public section");

        if (!isstatic && acode != NULL)
            yyerror("%AccessCode cannot be specified for non-static class variables");
    }

    if (isstatic && pt->genc)
        yyerror("Cannot have static members in a C structure");

    if (gcode != NULL || scode != NULL)
    {
        if (acode != NULL)
            yyerror("Cannot mix %AccessCode and %GetCode or %SetCode");

        if (escope == NULL)
            yyerror("Cannot specify %GetCode or %SetCode for global variables");
    }

    applyTypeFlags(mod, type, of);

    nd = cacheName(pt, getPythonName(mod, of, name));

    if (inMainModule())
        setIsUsedName(nd);

    checkAttributes(pt, mod, escope, NULL, nd->text, FALSE);

    var = sipMalloc(sizeof (varDef));

    var->pyname = nd;
    var->fqcname = text2scopedName((escope != NULL ? escope->iff : NULL),
            name);
    var->ecd = escope;
    var->module = mod;
    var->varflags = 0;
    var->no_typehint = getNoTypeHint(of);
    var->type = *type;
    appendCodeBlock(&var->accessfunc, acode);
    appendCodeBlock(&var->getcode, gcode);
    appendCodeBlock(&var->setcode, scode);

    if (isstatic || (escope != NULL && escope->iff->type == namespace_iface))
        setIsStaticVar(var);

    if (getOptFlag(of, "NoSetter", bool_flag) != NULL)
        setNoSetter(var);

    addVariable(pt, var);
}


/*
 * Create a new ctor.
 */
static void newCtor(moduleDef *mod, char *name, int sectFlags,
        signatureDef *args, optFlags *optflgs, codeBlock *methodcode,
        throwArgs *exceptions, signatureDef *cppsig, int explicit,
        codeBlock *docstring)
{
    ctorDef *ct, **ctp;
    classDef *cd = currentScope();

    /* Check the name of the constructor. */
    if (strcmp(classBaseName(cd), name) != 0)
        yyerror("Constructor doesn't have the same name as its class");

    if (docstring != NULL)
        appendCodeBlock(&cd->docstring, docstring);

    /* Add to the list of constructors. */
    ct = sipMalloc(sizeof (ctorDef));

    if (sectFlags & SECT_IS_PROT && makeProtPublic)
    {
        sectFlags &= ~SECT_IS_PROT;
        sectFlags |= SECT_IS_PUBLIC;
    }

    /* Allow the signature to be used like an function signature. */
    memset(&args->result, 0, sizeof (argDef));
    args->result.atype = void_type;

    ct->ctorflags = sectFlags;
    ct->no_typehint = getNoTypeHint(optflgs);
    ct->api_range = getAPIRange(optflgs);
    ct->pysig = *args;
    ct->cppsig = (cppsig != NULL ? cppsig : &ct->pysig);
    ct->exceptions = exceptions;
    appendCodeBlock(&ct->methodcode, methodcode);

    if (!isPrivateCtor(ct))
        setCanCreate(cd);

    if (isProtectedCtor(ct))
        setHasShadow(cd);

    if (explicit)
        setIsExplicitCtor(ct);

    getHooks(optflgs, &ct->prehook, &ct->posthook);

    if (getReleaseGIL(optflgs))
        setIsReleaseGILCtor(ct);
    else if (getHoldGIL(optflgs))
        setIsHoldGILCtor(ct);

    if (getTransfer(optflgs))
        setIsResultTransferredCtor(ct);

    if (getDeprecated(optflgs))
        setIsDeprecatedCtor(ct);

    if (!isPrivateCtor(ct))
        ct->kwargs = keywordArgs(mod, optflgs, &ct->pysig, FALSE);

    if (methodcode == NULL && getOptFlag(optflgs, "NoRaisesPyException", bool_flag) == NULL)
    {
        if (allRaisePyException(mod) || getOptFlag(optflgs, "RaisesPyException", bool_flag) != NULL)
            setRaisesPyExceptionCtor(ct);
    }

    if (getOptFlag(optflgs, "NoDerived", bool_flag) != NULL)
    {
        if (cppsig != NULL)
            yyerror("The /NoDerived/ annotation cannot be used with a C++ signature");

        if (methodcode == NULL)
            yyerror("The /NoDerived/ annotation must be used with %MethodCode");

        ct->cppsig = NULL;
    }

    if (getOptFlag(optflgs, "Default", bool_flag) != NULL)
    {
        if (cd->defctor != NULL)
            yyerror("A constructor with the /Default/ annotation has already been defined");

        cd->defctor = ct;
    }

    /* Append to the list. */
    for (ctp = &cd->ctors; *ctp != NULL; ctp = &(*ctp)->next)
        ;

    *ctp = ct;
}


/*
 * Create a new function.
 */
static void newFunction(sipSpec *pt, moduleDef *mod, classDef *c_scope,
        mappedTypeDef *mt_scope, int sflags, int isstatic, int issignal,
        int isslot, int isvirt, char *name, signatureDef *sig, int isconst,
        int isabstract, optFlags *optflgs, codeBlock *methodcode,
        codeBlock *vcode, codeBlock *virtcallcode, throwArgs *exceptions,
        signatureDef *cppsig, codeBlock *docstring)
{
    static const char *annos[] = {
        "__len__",
        "__imatmul__",
        "__matmul__",
        "AbortOnException",
        "AllowNone",
        "API",
        "AutoGen",
        "Deprecated",
        "DisallowNone",
        "DocType",
        "Encoding",
        "Factory",
        "HoldGIL",
        "KeywordArgs",
        "KeepReference",
        "NewThread",
        "NoArgParser",
        "NoCopy",
        "NoRaisesPyException",
        "NoTypeHint",
        "NoVirtualErrorHandler",
        "Numeric",
        "PostHook",
        "PreHook",
        "PyInt",
        "PyName",
        "PyQtSignalHack",
        "RaisesPyException",
        "ReleaseGIL",
        "Sequence",
        "VirtualErrorHandler",
        "Transfer",
        "TransferBack",
        "TransferThis",
        "TypeHint",
        NULL
    };

    const char *pyname, *virt_error_handler;
    int factory, xferback, no_arg_parser, no_virt_error_handler;
    overDef *od, **odp, **headp;
    optFlag *of;
    virtHandlerDef *vhd;

    checkAnnos(optflgs, annos);

    /* Extra checks for a C module. */
    if (pt->genc)
    {
        if (c_scope != NULL)
            yyerror("Function declaration not allowed in a struct in a C module");

        if (isstatic)
            yyerror("Static functions not allowed in a C module");

        if (exceptions != NULL)
            yyerror("Exceptions not allowed in a C module");

        /* Handle C void prototypes. */
        if (sig->nrArgs == 1)
        {
            argDef *vad = &sig->args[0];

            if (vad->atype == void_type && vad->nrderefs == 0)
                sig->nrArgs = 0;
        }
    }

    if (mt_scope != NULL)
        headp = &mt_scope->overs;
    else if (c_scope != NULL)
        headp = &c_scope->overs;
    else
        headp = &mod->overs;

    /*
     * See if the function has a non-lazy method.  These are methods that
     * Python expects to see defined in the type before any instance of the
     * type is created.
     */
    if (c_scope != NULL)
    {
        static const char *lazy[] = {
            "__getattribute__",
            "__getattr__",
            "__enter__",
            "__exit__",
            "__aenter__",
            "__aexit__",
            NULL
        };

        const char **l;

        for (l = lazy; *l != NULL; ++l)
            if (strcmp(name, *l) == 0)
            {
                setHasNonlazyMethod(c_scope);
                break;
            }
    }

    /* See if it is a factory method. */
    if (getOptFlag(optflgs, "Factory", bool_flag) != NULL)
        factory = TRUE;
    else
    {
        int a;

        factory = FALSE;

        /* Check /TransferThis/ wasn't specified. */
        if (c_scope == NULL || isstatic)
            for (a = 0; a < sig->nrArgs; ++a)
                if (isThisTransferred(&sig->args[a]))
                    yyerror("/TransferThis/ may only be specified in constructors and class methods");
    }

    /* See if the result is to be returned to Python ownership. */
    xferback = (getOptFlag(optflgs, "TransferBack", bool_flag) != NULL);

    if (factory && xferback)
        yyerror("/TransferBack/ and /Factory/ cannot both be specified");

    /* Create a new overload definition. */

    od = sipMalloc(sizeof (overDef));

    getSourceLocation(&od->sloc);

    /* Set the overload flags. */

    if ((sflags & SECT_IS_PROT) && makeProtPublic)
    {
        sflags &= ~SECT_IS_PROT;
        sflags |= SECT_IS_PUBLIC | OVER_REALLY_PROT;
    }

    od->overflags = sflags;

    if (issignal)
    {
        resetIsSlot(od);
        setIsSignal(od);
    }
    else if (isslot)
    {
        resetIsSignal(od);
        setIsSlot(od);
    }

    od->no_typehint = getNoTypeHint(optflgs);

    if (isSignal(od))
        if ((of = getOptFlag(optflgs, "PyQtSignalHack", integer_flag)) != NULL)
            od->pyqt_signal_hack = of->fvalue.ival;

    if (factory)
        setIsFactory(od);

    if (xferback)
        setIsResultTransferredBack(od);

    if (getTransfer(optflgs))
        setIsResultTransferred(od);

    if (getOptFlag(optflgs, "TransferThis", bool_flag) != NULL)
        setIsThisTransferredMeth(od);

    if (methodcode == NULL && getOptFlag(optflgs, "NoRaisesPyException", bool_flag) == NULL)
    {
        if (allRaisePyException(mod) || getOptFlag(optflgs, "RaisesPyException", bool_flag) != NULL)
            setRaisesPyException(od);
    }

    if (isProtected(od))
        setHasShadow(c_scope);

    if ((isSlot(od) || isSignal(od)) && !isPrivate(od))
    {
        if (isSignal(od))
            setHasShadow(c_scope);

        pt->sigslots = TRUE;
    }

    if (isSignal(od) && (methodcode != NULL || vcode != NULL || virtcallcode != NULL))
        yyerror("Cannot provide code for signals");

    if (isstatic)
    {
        if (isSignal(od))
            yyerror("Static functions cannot be signals");

        if (isvirt)
            yyerror("Static functions cannot be virtual");

        setIsStatic(od);
    }

    if (isconst)
        setIsConst(od);

    if (isabstract)
    {
        if (sflags == 0)
            yyerror("Non-class function specified as abstract");

        setIsAbstract(od);
    }

    if ((of = getOptFlag(optflgs, "AutoGen", opt_name_flag)) != NULL)
    {
        if (of->fvalue.sval == NULL || isEnabledFeature(of->fvalue.sval))
            setIsAutoGen(od);
    }

    virt_error_handler = getVirtErrorHandler(optflgs);
    no_virt_error_handler = (getOptFlag(optflgs, "NoVirtualErrorHandler", bool_flag) != NULL);

    if (isvirt)
    {
        if (isSignal(od) && pluginPyQt3(pt))
            yyerror("Virtual signals aren't supported");

        setIsVirtual(od);
        setHasShadow(c_scope);

        vhd = sipMalloc(sizeof (virtHandlerDef));

        vhd->virthandlernr = -1;
        vhd->vhflags = 0;
        vhd->pysig = &od->pysig;
        vhd->cppsig = (cppsig != NULL ? cppsig : &od->pysig);
        appendCodeBlock(&vhd->virtcode, vcode);

        if (factory || xferback)
            setIsTransferVH(vhd);

        if (getOptFlag(optflgs, "AbortOnException", bool_flag) != NULL)
            setAbortOnException(vhd);

        if (no_virt_error_handler)
        {
            if (virt_error_handler != NULL)
                yyerror("/VirtualErrorHandler/ and /NoVirtualErrorHandler/ provided");

            setNoErrorHandler(od);
        }
        else
        {
            od->virt_error_handler = virt_error_handler;
        }

        /*
         * Only add it to the module's virtual handlers if we are not in a
         * class template.
         */
        if (!currentIsTemplate)
        {
            vhd->module = mod;

            vhd->next = mod->virthandlers;
            mod->virthandlers = vhd;
        }
    }
    else
    {
        if (vcode != NULL)
            yyerror("%VirtualCatcherCode provided for non-virtual function");

        if (virt_error_handler != NULL)
            yyerror("/VirtualErrorHandler/ provided for non-virtual function");

        if (no_virt_error_handler)
            yyerror("/NoVirtualErrorHandler/ provided for non-virtual function");

        vhd = NULL;
    }

    od->cppname = name;
    od->pysig = *sig;
    od->cppsig = (cppsig != NULL ? cppsig : &od->pysig);
    od->exceptions = exceptions;
    appendCodeBlock(&od->methodcode, methodcode);
    appendCodeBlock(&od->virtcallcode, virtcallcode);
    od->virthandler = vhd;

    no_arg_parser = (getOptFlag(optflgs, "NoArgParser", bool_flag) != NULL);

    if (no_arg_parser)
    {
        if (methodcode == NULL)
            yyerror("%MethodCode must be supplied if /NoArgParser/ is specified");
    }
    else
    {
        /*
         * The argument parser requires that there is nothing after an
         * ellipsis.
         */
        checkEllipsis(sig);
    }

    if (cppsig != NULL)
        checkEllipsis(cppsig);

    if (getOptFlag(optflgs, "NoCopy", bool_flag) != NULL)
        setNoCopy(&od->pysig.result);

    if (getAllowNone(optflgs))
        setAllowNone(&od->pysig.result);

    if (getDisallowNone(optflgs))
        setDisallowNone(&od->pysig.result);

    handleKeepReference(optflgs, &od->pysig.result, mod);

    pyname = getPythonName(mod, optflgs, name);

    od->common = findFunction(pt, mod, c_scope, mt_scope, pyname,
            (methodcode != NULL), sig->nrArgs, no_arg_parser);

    if (isProtected(od))
        setHasProtected(od->common);

    if (strcmp(pyname, "__delattr__") == 0)
        setIsDelattr(od);

    if (docstring != NULL)
        appendCodeBlock(&od->common->docstring, docstring);

    od->api_range = getAPIRange(optflgs);

    if (od->api_range == NULL)
        setNotVersioned(od->common);

    if (getOptFlag(optflgs, "Numeric", bool_flag) != NULL)
    {
        if (isSequence(od->common))
            yyerror("/Sequence/ has already been specified");

        setIsNumeric(od->common);
    }

    if (getOptFlag(optflgs, "Sequence", bool_flag) != NULL)
    {
        if (isNumeric(od->common))
            yyerror("/Numeric/ has already been specified");

        setIsSequence(od->common);
    }

    /* Methods that run in new threads must be virtual. */
    if (getOptFlag(optflgs, "NewThread", bool_flag) != NULL)
    {
        argDef *res;

        if (!isvirt)
            yyerror("/NewThread/ may only be specified for virtual functions");

        /*
         * This is an arbitary limitation to make the code generator slightly
         * easier - laziness on my part.
         */
        res = &od->cppsig->result;

        if (res->atype != void_type || res->nrderefs != 0)
            yyerror("/NewThread/ may only be specified for void functions");

        setIsNewThread(od);
    }

    getHooks(optflgs, &od->prehook, &od->posthook);

    if (getReleaseGIL(optflgs))
        setIsReleaseGIL(od);
    else if (getHoldGIL(optflgs))
        setIsHoldGIL(od);

    if (getDeprecated(optflgs))
        setIsDeprecated(od);

    if (!isPrivate(od) && !isSignal(od) && (od->common->slot == no_slot || od->common->slot == call_slot))
    {
        od->kwargs = keywordArgs(mod, optflgs, &od->pysig, hasProtected(od->common));

        if (od->kwargs != NoKwArgs)
            setUseKeywordArgs(od->common);

        /*
         * If the overload is protected and defined in an imported module then
         * we need to make sure that any other overloads' keyword argument
         * names are marked as used.
         */
        if (isProtected(od) && !inMainModule())
        {
            overDef *kwod;

            for (kwod = c_scope->overs; kwod != NULL; kwod = kwod->next)
                if (kwod->common == od->common && kwod->kwargs != NoKwArgs)
                {
                    int a;

                    for (a = 0; a < kwod->pysig.nrArgs; ++a)
                    {
                        argDef *ad = &kwod->pysig.args[a];

                        if (kwod->kwargs == OptionalKwArgs && ad->defval == NULL)
                            continue;

                        if (ad->name != NULL)
                            setIsUsedName(ad->name);
                    }
                }
        }
    }

    od->next = NULL;

    /* See if we want to auto-generate some methods. */
    if (getOptFlag(optflgs, "__len__", bool_flag) != NULL)
    {
        overDef *len;

        len = sipMalloc(sizeof (overDef));

        len->cppname = "__len__";
        len->overflags = SECT_IS_PUBLIC;
        len->pysig.result.atype = ssize_type;
        len->pysig.nrArgs = 0;
        len->cppsig = &len->pysig;

        if ((len->methodcode = od->methodcode) == NULL)
        {
            char *buf = sipStrdup("            sipRes = (SIP_SSIZE_T)sipCpp->");
            codeBlock *code;

            append(&buf, od->cppname);
            append(&buf, "();\n");

            code = sipMalloc(sizeof (codeBlock));

            code->frag = buf;
            code->filename = "Auto-generated";
            code->linenr = 1;

            appendCodeBlock(&len->methodcode, code);
        }

        len->common = findFunction(pt, mod, c_scope, mt_scope, len->cppname,
                TRUE, 0, FALSE);

        len->next = od->next;
        od->next = len;
    }

    if (getOptFlag(optflgs, "__matmul__", bool_flag) != NULL)
    {
        overDef *matmul;

        matmul = sipMalloc(sizeof (overDef));

        matmul->cppname = "__matmul__";
        matmul->overflags = SECT_IS_PUBLIC;
        matmul->pysig = od->pysig;
        matmul->cppsig = (cppsig != NULL ? cppsig : &matmul->pysig);

        matmul->methodcode = od->methodcode;

        matmul->common = findFunction(pt, mod, c_scope, mt_scope,
                matmul->cppname, (matmul->methodcode != NULL),
                matmul->pysig.nrArgs, FALSE);

        matmul->next = od->next;
        od->next = matmul;
    }

    if (getOptFlag(optflgs, "__imatmul__", bool_flag) != NULL)
    {
        overDef *imatmul;

        imatmul = sipMalloc(sizeof (overDef));

        imatmul->cppname = "__imatmul__";
        imatmul->overflags = SECT_IS_PUBLIC;
        imatmul->pysig = od->pysig;
        imatmul->cppsig = (cppsig != NULL ? cppsig : &imatmul->pysig);

        imatmul->methodcode = od->methodcode;

        imatmul->common = findFunction(pt, mod, c_scope, mt_scope,
                imatmul->cppname, (imatmul->methodcode != NULL),
                imatmul->pysig.nrArgs, FALSE);

        imatmul->next = od->next;
        od->next = imatmul;
    }

    /* Append to the list. */
    for (odp = headp; *odp != NULL; odp = &(*odp)->next)
        ;

    *odp = od;
}


/*
 * Return the Python name based on the C/C++ name and any /PyName/ annotation.
 */
static const char *getPythonName(moduleDef *mod, optFlags *optflgs,
        const char *cname)
{
    const char *pname;
    optFlag *of;
    autoPyNameDef *apnd;

    /* Use the explicit name if given. */
    if ((of = getOptFlag(optflgs, "PyName", name_flag)) != NULL)
        return of->fvalue.sval;

    /* Apply any automatic naming rules. */
    pname = cname;

    for (apnd = mod->autopyname; apnd != NULL; apnd = apnd->next)
    {
        size_t len = strlen(apnd->remove_leading);

        if (strncmp(pname, apnd->remove_leading, len) == 0)
            pname += len;
    }

    return pname;
}


/*
 * Cache a name in a module.  Entries in the cache are stored in order of
 * decreasing length.
 */
nameDef *cacheName(sipSpec *pt, const char *name)
{
    nameDef *nd, **ndp;
    size_t len;

    /* Allow callers to be lazy about checking if there is really a name. */
    if (name == NULL)
        return NULL;

    /* Skip entries that are too large. */
    ndp = &pt->namecache;
    len = strlen(name);

    while (*ndp != NULL && (*ndp)->len > len)
        ndp = &(*ndp)->next;

    /* Check entries that are the right length. */
    for (nd = *ndp; nd != NULL && nd->len == len; nd = nd->next)
        if (memcmp(nd->text, name, len) == 0)
            return nd;

    /* Create a new one. */
    nd = sipMalloc(sizeof (nameDef));

    nd->nameflags = 0;
    nd->text = name;
    nd->len = len;
    nd->next = *ndp;

    *ndp = nd;

    return nd;
}


/*
 * Find (or create) an overloaded function name.
 */
static memberDef *findFunction(sipSpec *pt, moduleDef *mod, classDef *c_scope,
        mappedTypeDef *mt_scope, const char *pname, int hwcode, int nrargs,
        int no_arg_parser)
{
    static struct slot_map {
        const char *name;   /* The slot name. */
        slotType type;      /* The corresponding type. */
        int needs_hwcode;   /* Set if handwritten code is required. */
        int nrargs;         /* Nr. of arguments. */
    } slot_table[] = {
        {"__str__", str_slot, TRUE, 0},
        {"__int__", int_slot, FALSE, 0},
        {"__long__", long_slot, FALSE, 0},
        {"__float__", float_slot, FALSE, 0},
        {"__len__", len_slot, TRUE, 0},
        {"__contains__", contains_slot, TRUE, 1},
        {"__add__", add_slot, FALSE, 1},
        {"__sub__", sub_slot, FALSE, 1},
        {"__mul__", mul_slot, FALSE, 1},
        {"__div__", div_slot, FALSE, 1},
        {"__mod__", mod_slot, FALSE, 1},
        {"__floordiv__", floordiv_slot, TRUE, 1},
        {"__truediv__", truediv_slot, FALSE, 1},
        {"__and__", and_slot, FALSE, 1},
        {"__or__", or_slot, FALSE, 1},
        {"__xor__", xor_slot, FALSE, 1},
        {"__lshift__", lshift_slot, FALSE, 1},
        {"__rshift__", rshift_slot, FALSE, 1},
        {"__iadd__", iadd_slot, FALSE, 1},
        {"__isub__", isub_slot, FALSE, 1},
        {"__imul__", imul_slot, FALSE, 1},
        {"__idiv__", idiv_slot, FALSE, 1},
        {"__imod__", imod_slot, FALSE, 1},
        {"__ifloordiv__", ifloordiv_slot, TRUE, 1},
        {"__itruediv__", itruediv_slot, FALSE, 1},
        {"__iand__", iand_slot, FALSE, 1},
        {"__ior__", ior_slot, FALSE, 1},
        {"__ixor__", ixor_slot, FALSE, 1},
        {"__ilshift__", ilshift_slot, FALSE, 1},
        {"__irshift__", irshift_slot, FALSE, 1},
        {"__invert__", invert_slot, FALSE, 0},
        {"__call__", call_slot, FALSE, -1},
        {"__getitem__", getitem_slot, FALSE, 1},
        {"__setitem__", setitem_slot, TRUE, 2},
        {"__delitem__", delitem_slot, TRUE, 1},
        {"__lt__", lt_slot, FALSE, 1},
        {"__le__", le_slot, FALSE, 1},
        {"__eq__", eq_slot, FALSE, 1},
        {"__ne__", ne_slot, FALSE, 1},
        {"__gt__", gt_slot, FALSE, 1},
        {"__ge__", ge_slot, FALSE, 1},
        {"__cmp__", cmp_slot, FALSE, 1},
        {"__bool__", bool_slot, TRUE, 0},
        {"__nonzero__", bool_slot, TRUE, 0},
        {"__neg__", neg_slot, FALSE, 0},
        {"__pos__", pos_slot, FALSE, 0},
        {"__abs__", abs_slot, TRUE, 0},
        {"__repr__", repr_slot, TRUE, 0},
        {"__hash__", hash_slot, TRUE, 0},
        {"__index__", index_slot, TRUE, 0},
        {"__iter__", iter_slot, TRUE, 0},
        {"__next__", next_slot, TRUE, 0},
        {"__setattr__", setattr_slot, TRUE, 2},
        {"__delattr__", delattr_slot, TRUE, 1},
        {"__matmul__", matmul_slot, FALSE, 1},
        {"__imatmul__", imatmul_slot, FALSE, 1},
        {"__await__", await_slot, TRUE, 0},
        {"__aiter__", aiter_slot, TRUE, 0},
        {"__anext__", anext_slot, TRUE, 0},
        {NULL, no_slot, FALSE, 0}
    };

    memberDef *md, **flist;
    struct slot_map *sm;
    slotType st;

    /* Get the slot type. */
    st = no_slot;

    for (sm = slot_table; sm->name != NULL; ++sm)
        if (strcmp(sm->name, pname) == 0)
        {
            if (sm->needs_hwcode && !hwcode)
                yyerror("This Python slot requires %MethodCode");

            if (sm->nrargs >= 0)
            {
                if (mt_scope == NULL && c_scope == NULL)
                {
                    /* Global operators need one extra argument. */
                    if (sm -> nrargs + 1 != nrargs)
                        yyerror("Incorrect number of arguments to global operator");
                }
                else if (sm->nrargs != nrargs)
                    yyerror("Incorrect number of arguments to Python slot");
            }

            st = sm->type;

            break;
        }

    /* Check there is no name clash. */
    checkAttributes(pt, mod, c_scope, mt_scope, pname, TRUE);

    /* See if it already exists. */
    if (mt_scope != NULL)
        flist = &mt_scope->members;
    else if (c_scope != NULL)
        flist = &c_scope->members;
    else
        flist = &mod->othfuncs;

    /* __delattr__ is implemented as __setattr__. */
    if (st == delattr_slot)
    {
        if (inMainModule())
            setIsUsedName(cacheName(pt, pname));

        st = setattr_slot;
        pname = "__setattr__";
    }

    for (md = *flist; md != NULL; md = md->next)
        if (strcmp(md->pyname->text, pname) == 0 && md->module == mod)
            break;

    if (md == NULL)
    {
        /* Create a new one. */
        md = sipMalloc(sizeof (memberDef));

        md->pyname = cacheName(pt, pname);
        md->memberflags = 0;
        md->slot = st;
        md->module = mod;
        md->next = *flist;

        *flist = md;

        if (inMainModule())
            setIsUsedName(md->pyname);

        if (no_arg_parser)
            setNoArgParser(md);
    }
    else if (noArgParser(md))
        yyerror("Another overload has already been defined that is annotated as /NoArgParser/");

    /* Global operators are a subset. */
    if (mt_scope == NULL && c_scope == NULL && st != no_slot && st != neg_slot && st != pos_slot && !isNumberSlot(md) && !isInplaceNumberSlot(md) && !isRichCompareSlot(md))
        yyerror("Global operators must be either numeric or comparison operators");

    return md;
}


/*
 * Search a set of flags for a particular one.
 */
static optFlag *findOptFlag(optFlags *flgs, const char *name)
{
    int f;

    for (f = 0; f < flgs->nrFlags; ++f)
    {
        optFlag *of = &flgs->flags[f];

        if (strcmp(of->fname, name) == 0)
            return of;
    }

    return NULL;
}


/*
 * Search a set of flags for a particular one and check its type.
 */
static optFlag *getOptFlag(optFlags *flgs, const char *name, flagType ft)
{
    optFlag *of = findOptFlag(flgs, name);

    if (of != NULL)
    {
        /* An optional name can look like a boolean or a name. */
        if (ft == opt_name_flag)
        {
            if (of->ftype == bool_flag)
            {
                of->ftype = opt_name_flag;
                of->fvalue.sval = NULL;
            }
            else if (of->ftype == name_flag)
            {
                of->ftype = opt_name_flag;
            }
        }

        /* An optional integer can look like a boolean or an integer. */
        if (ft == opt_integer_flag)
        {
            if (of->ftype == bool_flag)
            {
                of->ftype = opt_integer_flag;
                of->fvalue.ival = -1;
            }
            else if (of->ftype == integer_flag)
            {
                of->ftype = opt_integer_flag;
            }
        }

        if (ft != of->ftype)
            yyerror("Annotation has a value of the wrong type");
    }

    return of;
}


/*
 * A name is going to be used as a Python attribute name within a Python scope
 * (ie. a Python dictionary), so check against what we already know is going in
 * the same scope in case there is a clash.
 */
static void checkAttributes(sipSpec *pt, moduleDef *mod, classDef *py_c_scope,
        mappedTypeDef *py_mt_scope, const char *attr, int isfunc)
{
    enumDef *ed;
    varDef *vd;
    classDef *cd;

    /* Check the enums. */

    for (ed = pt->enums; ed != NULL; ed = ed->next)
    {
        enumMemberDef *emd;

        if (ed->pyname == NULL)
            continue;

        if (py_c_scope != NULL)
        {
            if (ed->ecd != py_c_scope)
                continue;
        }
        else if (py_mt_scope != NULL)
        {
            if (ed->emtd != py_mt_scope)
                continue;
        }
        else if (ed->ecd != NULL || ed->emtd != NULL)
        {
            continue;
        }

        if (strcmp(ed->pyname->text, attr) == 0)
            yyerror("There is already an enum in scope with the same Python name");

        for (emd = ed->members; emd != NULL; emd = emd->next)
            if (strcmp(emd->pyname->text, attr) == 0)
                yyerror("There is already an enum member in scope with the same Python name");
    }

    /*
     * Only check the members if this attribute isn't a member because we
     * can handle members with the same name in the same scope.
     */
    if (!isfunc)
    {
        memberDef *md, *membs;
        overDef *overs;

        if (py_mt_scope != NULL)
        {
            membs = py_mt_scope->members;
            overs = py_mt_scope->overs;
        }
        else if (py_c_scope != NULL)
        {
            membs = py_c_scope->members;
            overs = py_c_scope->overs;
        }
        else
        {
            membs = mod->othfuncs;
            overs = mod->overs;
        }

        for (md = membs; md != NULL; md = md->next)
        {
            overDef *od;

            if (strcmp(md->pyname->text, attr) != 0)
                continue;

            /* Check for a conflict with all overloads. */
            for (od = overs; od != NULL; od = od->next)
            {
                if (od->common != md)
                    continue;

                yyerror("There is already a function in scope with the same Python name");
            }
        }
    }

    /* If the scope was a mapped type then that's all we have to check. */
    if (py_mt_scope != NULL)
        return;

    /* Check the variables. */
    for (vd = pt->vars; vd != NULL; vd = vd->next)
    {
        if (vd->ecd != py_c_scope)
            continue;

        if (strcmp(vd->pyname->text,attr) == 0)
            yyerror("There is already a variable in scope with the same Python name");
    }

    /* Check the classes. */
    for (cd = pt->classes; cd != NULL; cd = cd->next)
    {
        if (cd->ecd != py_c_scope || cd->pyname == NULL)
            continue;

        if (strcmp(cd->pyname->text, attr) == 0 && !isExternal(cd))
            yyerror("There is already a class or namespace in scope with the same Python name");
    }

    /* Check the exceptions. */
    if (py_c_scope == NULL)
    {
        exceptionDef *xd;

        for (xd = pt->exceptions; xd != NULL; xd = xd->next)
            if (xd->pyname != NULL && strcmp(xd->pyname, attr) == 0)
                yyerror("There is already an exception with the same Python name");
    }

    /* Check the properties. */
    if (py_c_scope != NULL)
    {
        propertyDef *pd;

        for (pd = py_c_scope->properties; pd != NULL; pd = pd->next)
            if (strcmp(pd->name->text, attr) == 0)
                yyerror("There is already a property with the same name");
    }
}


/*
 * Append a code block to a list of them.
 */
static void appendCodeBlock(codeBlockList **headp, codeBlock *cb)
{
    codeBlockList *cbl;

    /* Handle the trivial case. */
    if (cb == NULL)
        return;

    /* Find the end of the list. */
    while (*headp != NULL)
    {
        /* Ignore if the block is already in the list. */
        if ((*headp)->block == cb)
            return;

        headp = &(*headp)->next;
    }

    cbl = sipMalloc(sizeof (codeBlockList));
    cbl->block = cb;

    *headp = cbl;
}


/*
 * Append a code block list to an existing list.
 */
void appendCodeBlockList(codeBlockList **headp, codeBlockList *cbl)
{
    while (cbl != NULL)
    {
        appendCodeBlock(headp, cbl->block);
        cbl = cbl->next;
    }
}


/*
 * Handle the end of a fully parsed a file.
 */
static void handleEOF()
{
    /*
     * Check that the number of nested if's is the same as when we started
     * the file.
     */

    if (skipStackPtr > currentContext.ifdepth)
        fatal("Too many %%If statements in %s\n", previousFile);

    if (skipStackPtr < currentContext.ifdepth)
        fatal("Too many %%End statements in %s\n", previousFile);
}


/*
 * Handle the end of a fully parsed a module.
 */
static void handleEOM()
{
    moduleDef *from;

    /* Check it has been named. */
    if (currentModule->name == NULL)
        fatal("No %%Module has been specified for module defined in %s\n",
                previousFile);

    from = currentContext.prevmod;

    if (from != NULL)
    {
        if (from->encoding == no_type)
            from->encoding = currentModule->encoding;

        if (isCallSuperInitUndefined(from))
        {
            if (isCallSuperInitYes(currentModule))
                setCallSuperInitYes(from);
            else
                setCallSuperInitNo(from);
        }
    }

    /* The previous module is now current. */
    currentModule = from;
}


/*
 * Find an existing qualifier.
 */
static qualDef *findQualifier(const char *name)
{
    moduleDef *mod;

    for (mod = currentSpec->modules; mod != NULL; mod = mod->next)
    {
        qualDef *qd;

        for (qd = mod->qualifiers; qd != NULL; qd = qd->next)
            if (strcmp(qd->name, name) == 0)
                return qd;
    }

    /* Qualifiers corresponding to the SIP version are created on the fly. */
    if (name[0] == 'S' && name[1] == 'I' && name[2] == 'P' && name[3] == '_')
    {
        const char *cp = &name[3];
        int major, minor, patch;

        cp = getInt(cp, &major);
        cp = getInt(cp, &minor);
        cp = getInt(cp, &patch);

        if (*cp != '\0')
            yyerror("Unexpected character after SIP version number");

        return allocQualifier(currentModule, -1,
                (major << 16) | (minor << 8) | patch, TRUE, name,
                time_qualifier);
    }

    return NULL;
}


/*
 * Get an integer from string.
 */
static const char *getInt(const char *cp, int *ip)
{
    /* Handle the default value. */
    *ip = 0;

    if (*cp == '\0')
        return cp;

    /* There must be a leading underscore. */
    if (*cp++ != '_')
        yyerror("An underscore must separate the parts of a SIP version number");

    while (isdigit(*cp))
    {
        *ip *= 10;
        *ip += *cp - '0';
        ++cp;
    }

    return cp;
}


/*
 * Find an existing API.
 */
apiVersionRangeDef *findAPI(sipSpec *pt, const char *name)
{
    moduleDef *mod;

    for (mod = pt->modules; mod != NULL; mod = mod->next)
    {
        apiVersionRangeDef *avd;

        for (avd = mod->api_versions; avd != NULL; avd = avd->next)
            if (strcmp(avd->api_name->text, name) == 0)
                return avd;
    }

    return NULL;
}


/*
 * Return a copy of a scoped name.
 */
scopedNameDef *copyScopedName(scopedNameDef *snd)
{
    scopedNameDef *head;

    head = NULL;

    while (snd != NULL)
    {
        appendScopedName(&head,text2scopePart(snd -> name));
        snd = snd -> next;
    }

    return head;
}


/*
 * Append a name to a list of scopes.
 */
void appendScopedName(scopedNameDef **headp,scopedNameDef *newsnd)
{
    while (*headp != NULL)
        headp = &(*headp) -> next;

    *headp = newsnd;
}


/*
 * Free a scoped name - but not the text itself.
 */
void freeScopedName(scopedNameDef *snd)
{
    while (snd != NULL)
    {
        scopedNameDef *next = snd -> next;

        free(snd);

        snd = next;
    }
}


/*
 * Convert a text string to a scope part structure.
 */
static scopedNameDef *text2scopePart(char *text)
{
    scopedNameDef *snd;

    snd = sipMalloc(sizeof (scopedNameDef));

    snd->name = text;
    snd->next = NULL;

    return snd;
}


/*
 * Convert a text string to a fully scoped name.
 */
static scopedNameDef *text2scopedName(ifaceFileDef *scope, char *text)
{
    return scopeScopedName(scope, text2scopePart(text));
}


/*
 * Prepend any current scope to a scoped name.
 */
static scopedNameDef *scopeScopedName(ifaceFileDef *scope, scopedNameDef *name)
{
    scopedNameDef *snd;

    snd = (scope != NULL ? copyScopedName(scope->fqcname) : NULL);

    appendScopedName(&snd, name);

    return snd;
}


/*
 * Return a pointer to the tail part of a scoped name.
 */
char *scopedNameTail(scopedNameDef *snd)
{
    if (snd == NULL)
        return NULL;

    while (snd -> next != NULL)
        snd = snd -> next;

    return snd -> name;
}


/*
 * Push the given scope onto the scope stack.
 */
static void pushScope(classDef *scope)
{
    if (currentScopeIdx >= MAX_NESTED_SCOPE)
        fatal("Internal error: increase the value of MAX_NESTED_SCOPE\n");

    scopeStack[currentScopeIdx] = scope;
    sectFlagsStack[currentScopeIdx] = sectionFlags;

    ++currentScopeIdx;
}


/*
 * Pop the scope stack.
 */
static void popScope(void)
{
    if (currentScopeIdx > 0)
        sectionFlags = sectFlagsStack[--currentScopeIdx];
}


/*
 * Return non-zero if the current input should be parsed rather than be
 * skipped.
 */
static int notSkipping()
{
    return (skipStackPtr == 0 ? TRUE : skipStack[skipStackPtr - 1]);
}


/*
 * Return the value of an expression involving a time period.
 */
static int timePeriod(const char *lname, const char *uname)
{
    int line;
    qualDef *qd, *lower, *upper;
    moduleDef *mod;

    if (lname == NULL)
        lower = NULL;
    else if ((lower = findQualifier(lname)) == NULL || lower->qtype != time_qualifier)
        yyerror("Lower bound is not a time version");

    if (uname == NULL)
        upper = NULL;
    else if ((upper = findQualifier(uname)) == NULL || upper->qtype != time_qualifier)
        yyerror("Upper bound is not a time version");

    /* Sanity checks on the bounds. */
    if (lower == NULL && upper == NULL)
        yyerror("Lower and upper bounds cannot both be omitted");

    if (lower != NULL && upper != NULL)
    {
        if (lower->module != upper->module || lower->line != upper->line)
            yyerror("Lower and upper bounds are from different timelines");

        if (lower == upper)
            yyerror("Lower and upper bounds must be different");

        if (lower->order > upper->order)
            yyerror("Later version specified as lower bound");
    }

    /* Go through each slot in the relevant timeline. */
    if (lower != NULL)
    {
        mod = lower->module;
        line = lower->line;
    }
    else
    {
        mod = upper->module;
        line = upper->line;
    }

    /* Handle the SIP version number pseudo-timeline. */
    if (line < 0)
    {
        if (lower != NULL && SIP_VERSION < lower->order)
            return FALSE;

        if (upper != NULL && SIP_VERSION >= upper->order)
            return FALSE;

        return TRUE;
    }

    for (qd = mod->qualifiers; qd != NULL; qd = qd->next)
    {
        if (qd->qtype != time_qualifier || qd->line != line)
            continue;

        if (selectedQualifier(neededQualifiers, qd))
        {
            if (lower != NULL && qd->order < lower->order)
                return FALSE;

            if (upper != NULL && qd->order >= upper->order)
                return FALSE;

            return TRUE;
        }
    }

    /*
     * If there is no upper bound then assume the expression is true unless
     * the lower bound is a backstop.
     */
    if (upper == NULL)
        return !isBackstop(lower);

    /*
     * If the upper limit corresponds to a backstop then assume the expression
     * is true.
     */
    return isBackstop(upper);
}


/*
 * See if a qualifier is a backstop.
 */
static int isBackstop(qualDef *qd)
{
    stringList *sl;

    for (sl = backstops; sl != NULL; sl = sl->next)
        if (strcmp(qd->name, sl->s) == 0)
            return TRUE;

    return FALSE;
}


/*
 * Return the value of an expression involving a single platform or feature.
 */
static int platOrFeature(char *name,int optnot)
{
    int this;
    qualDef *qd;

    if ((qd = findQualifier(name)) == NULL || qd -> qtype == time_qualifier)
        yyerror("No such platform or feature");

    /* Assume this sub-expression is false. */

    this = FALSE;

    if (qd -> qtype == feature_qualifier)
    {
        if (!excludedFeature(excludedQualifiers, qd))
            this = TRUE;
    }
    else if (selectedQualifier(neededQualifiers, qd))
    {
        this = TRUE;
    }

    if (optnot)
        this = !this;

    return this;
}


/*
 * Return TRUE if the given qualifier is excluded.
 */
int excludedFeature(stringList *xsl, qualDef *qd)
{
    while (xsl != NULL)
    {
        if (strcmp(qd->name, xsl->s) == 0)
            return TRUE;

        xsl = xsl->next;
    }

    return !qd->default_enabled;
}


/*
 * Return TRUE if the given qualifier is needed.
 */
int selectedQualifier(stringList *needed_qualifiers, qualDef *qd)
{
    stringList *sl;

    for (sl = needed_qualifiers; sl != NULL; sl = sl->next)
        if (strcmp(qd->name, sl->s) == 0)
            return qd->default_enabled;

    return FALSE;
}


/*
 * Return the current scope.  currentScope() is only valid if notSkipping()
 * returns non-zero.
 */
static classDef *currentScope(void)
{
    return (currentScopeIdx > 0 ? scopeStack[currentScopeIdx - 1] : NULL);
}


/*
 * Create a new qualifier.
 */
static void newQualifier(moduleDef *mod, int line, int order,
        int default_enabled, const char *name, qualType qt)
{
    /* Check it doesn't already exist. */
    if (findQualifier(name) != NULL)
        yyerror("Version is already defined");

    allocQualifier(mod, line, order, default_enabled, name, qt);
}


/*
 * Allocate a new qualifier.
 */
static qualDef *allocQualifier(moduleDef *mod, int line, int order,
        int default_enabled, const char *name, qualType qt)
{
    qualDef *qd;

    qd = sipMalloc(sizeof (qualDef));

    qd->name = name;
    qd->qtype = qt;
    qd->module = mod;
    qd->line = line;
    qd->order = order;
    qd->default_enabled = default_enabled;
    qd->next = mod->qualifiers;

    mod->qualifiers = qd;

    return qd;
}


/*
 * Create a new imported module.
 */
static void newImport(const char *filename)
{
    moduleDef *from, *mod;
    moduleListDef *mld;

    /* Create a new module if it has not already been defined. */
    for (mod = currentSpec->modules; mod != NULL; mod = mod->next)
        if (strcmp(mod->file, filename) == 0)
            break;

    from = currentModule;

    if (mod == NULL)
    {
        newModule(NULL, filename);
        mod = currentModule;
    }
    else if (from->encoding == no_type)
    {
        /* Import any defaults from the already parsed module. */
        from->encoding = mod->encoding;
    }

    /* Add the new import unless it has already been imported. */
    for (mld = from->imports; mld != NULL; mld = mld->next)
        if (mld->module == mod)
            return;

    mld = sipMalloc(sizeof (moduleListDef));
    mld->module = mod;
    mld->next = from->imports;

    from->imports = mld;
}


/*
 * Set up pointers to hook names.
 */
static void getHooks(optFlags *optflgs,char **pre,char **post)
{
    optFlag *of;

    if ((of = getOptFlag(optflgs,"PreHook",name_flag)) != NULL)
        *pre = of -> fvalue.sval;
    else
        *pre = NULL;

    if ((of = getOptFlag(optflgs,"PostHook",name_flag)) != NULL)
        *post = of -> fvalue.sval;
    else
        *post = NULL;
}


/*
 * Get the /Transfer/ option flag.
 */
static int getTransfer(optFlags *optflgs)
{
    return (getOptFlag(optflgs, "Transfer", bool_flag) != NULL);
}


/*
 * Get the /ReleaseGIL/ option flag.
 */
static int getReleaseGIL(optFlags *optflgs)
{
    return (getOptFlag(optflgs, "ReleaseGIL", bool_flag) != NULL);
}


/*
 * Get the /HoldGIL/ option flag.
 */
static int getHoldGIL(optFlags *optflgs)
{
    return (getOptFlag(optflgs, "HoldGIL", bool_flag) != NULL);
}


/*
 * Get the /Deprecated/ option flag.
 */
static int getDeprecated(optFlags *optflgs)
{
    return (getOptFlag(optflgs, "Deprecated", bool_flag) != NULL);
}


/*
 * Get the /AllowNone/ option flag.
 */
static int getAllowNone(optFlags *optflgs)
{
    return (getOptFlag(optflgs, "AllowNone", bool_flag) != NULL);
}


/*
 * Get the /DisallowNone/ option flag.
 */
static int getDisallowNone(optFlags *optflgs)
{
    return (getOptFlag(optflgs, "DisallowNone", bool_flag) != NULL);
}


/*
 * Get the /VirtualErrorHandler/ option flag.
 */
static const char *getVirtErrorHandler(optFlags *optflgs)
{
    optFlag *of = getOptFlag(optflgs, "VirtualErrorHandler", name_flag);

    if (of == NULL)
        return NULL;

    return of->fvalue.sval;
}


/*
 * Get the /DocType/ option flag.
 */
static const char *getDocType(optFlags *optflgs)
{
    optFlag *of = getOptFlag(optflgs, "DocType", string_flag);

    if (of == NULL)
        return NULL;

    deprecated("/DocType/ is deprecated\n");

    return of->fvalue.sval;
}


/*
 * Get the /TypeHintValue/ option flag.
 */
static const char *getTypeHintValue(optFlags *optflgs)
{
    optFlag *of = getOptFlag(optflgs, "TypeHintValue", string_flag);

    if (of != NULL)
        return of->fvalue.sval;

    if ((of = getOptFlag(optflgs, "DocValue", string_flag)) != NULL)
    {
        deprecated("/DocValue/ is deprecated\n");

        return of->fvalue.sval;
    }

    return NULL;
}


/*
 * Get the /TypeHint/, /TypeHintIn/ and /TypeHintOut/ option flags.
 */
static void getTypeHints(optFlags *optflgs, typeHintDef **in,
        typeHintDef **out)
{
    optFlag *of;
    typeHintDef *thd;

    if ((of = getOptFlag(optflgs, "TypeHint", string_flag)) != NULL)
        thd = newTypeHint(of->fvalue.sval);
    else
        thd = NULL;

    if ((of = getOptFlag(optflgs, "TypeHintIn", string_flag)) != NULL)
    {
        if (thd != NULL)
            yywarning("/TypeHintIn/ overrides /TypeHint/");

        *in = newTypeHint(of->fvalue.sval);
    }
    else
    {
        *in = thd;
    }

    if ((of = getOptFlag(optflgs, "TypeHintOut", string_flag)) != NULL)
    {
        if (thd != NULL)
            yywarning("/TypeHintOut/ overrides /TypeHint/");

        *out = newTypeHint(of->fvalue.sval);
    }
    else
    {
        *out = thd;
    }
}


/*
 * Get the /NoTypeHint/ option flag.
 */
static int getNoTypeHint(optFlags *optflgs)
{
    return (getOptFlag(optflgs, "NoTypeHint", bool_flag) != NULL);
}


/*
 * Return TRUE if the PyQt3 plugin was specified.
 */
int pluginPyQt3(sipSpec *pt)
{
    return stringFind(pt->plugins, "PyQt3");
}


/*
 * Return TRUE if the PyQt4 plugin was specified.
 */
int pluginPyQt4(sipSpec *pt)
{
    return stringFind(pt->plugins, "PyQt4");
}


/*
 * Return TRUE if the PyQt5 plugin was specified.
 */
int pluginPyQt5(sipSpec *pt)
{
    return stringFind(pt->plugins, "PyQt5");
}


/*
 * Return TRUE if a list of strings contains a given entry.
 */
static int stringFind(stringList *sl, const char *s)
{
    while (sl != NULL)
    {
        if (strcmp(sl->s, s) == 0)
            return TRUE;

        sl = sl->next;
    }

    return FALSE;
}


/*
 * Set the name of a module.
 */
static void setModuleName(sipSpec *pt, moduleDef *mod, const char *fullname)
{
    mod->fullname = cacheName(pt, fullname);

    if (inMainModule())
        setIsUsedName(mod->fullname);

    if ((mod->name = strrchr(fullname, '.')) != NULL)
        mod->name++;
    else
        mod->name = fullname;
}


/*
 * Define a new class and set its name.
 */
static void defineClass(scopedNameDef *snd, classList *supers, optFlags *of)
{
    classDef *cd, *c_scope = currentScope();
    typeHintDef *in, *out;

    getTypeHints(of, &in, &out);

    cd = newClass(currentSpec, class_iface, getAPIRange(of),
            scopeScopedName((c_scope != NULL ? c_scope->iff : NULL), snd),
            getVirtErrorHandler(of), in, out, getTypeHintValue(of));
    cd->supers = supers;

    pushScope(cd);
}


/*
 * Complete the definition of a class.
 */
static classDef *completeClass(scopedNameDef *snd, optFlags *of, int has_def)
{
    classDef *cd = currentScope();

    /* See if the class was defined or just declared. */
    if (has_def)
    {
        if (snd->next != NULL)
            yyerror("A scoped name cannot be given in a class/struct definition");

    }
    else if (cd->supers != NULL)
        yyerror("Class/struct has super-classes but no definition");
    else
        setIsOpaque(cd);

    finishClass(currentSpec, currentModule, cd, of);
    popScope();

    /*
     * Check that external classes have only been declared at the global scope.
     */
    if (isExternal(cd) && currentScope() != NULL)
        yyerror("External classes/structs can only be declared in the global scope");

    return cd;
}


/*
 * Add a variable to the list so that the list remains sorted.
 */
static void addVariable(sipSpec *pt, varDef *vd)
{
    varDef **at = &pt->vars;

    while (*at != NULL)
    {
        if (strcmp(vd->pyname->text, (*at)->pyname->text) < 0)
            break;

        at = &(*at)->next;
    }

    vd->next = *at;
    *at = vd;
}


/*
 * Update a type according to optional flags.
 */
static void applyTypeFlags(moduleDef *mod, argDef *ad, optFlags *flags)
{
    ad->doctype = getDocType(flags);
    getTypeHints(flags, &ad->typehint_in, &ad->typehint_out);

    if (getOptFlag(flags, "PyInt", bool_flag) != NULL)
    {
        if (ad->atype == string_type)
            ad->atype = byte_type;
        else if (ad->atype == sstring_type)
            ad->atype = sbyte_type;
        else if (ad->atype == ustring_type)
            ad->atype = ubyte_type;
    }

    if (ad->atype == string_type && !isArray(ad) && !isReference(ad))
    {
        optFlag *of;

        if ((of = getOptFlag(flags, "Encoding", string_flag)) == NULL)
        {
            if (mod->encoding != no_type)
                ad->atype = mod->encoding;
            else
                ad->atype = string_type;
        }
        else if ((ad->atype = convertEncoding(of->fvalue.sval)) == no_type)
            yyerror("The value of the /Encoding/ annotation must be one of \"ASCII\", \"Latin-1\", \"UTF-8\" or \"None\"");
    }
}


/*
 * Return the keyword argument support converted from a string.
 */
static KwArgs convertKwArgs(const char *kwargs)
{
    if (strcmp(kwargs, "None") == 0)
        return NoKwArgs;

    if (strcmp(kwargs, "All") == 0)
        return AllKwArgs;

    if (strcmp(kwargs, "Optional") == 0)
        return OptionalKwArgs;

    yyerror("The style of keyword argument support must be one of \"All\", \"Optional\" or \"None\"");
}


/*
 * Return the Format for a string.
 */
static Format convertFormat(const char *format)
{
    if (strcmp(format, "raw") == 0)
        return raw;

    if (strcmp(format, "deindented") == 0)
        return deindented;

    yyerror("The docstring format must be either \"raw\" or \"deindented\"");
}


/*
 * Return the argument type for a string with the given encoding or no_type if
 * the encoding was invalid.
 */
static argType convertEncoding(const char *encoding)
{
    if (strcmp(encoding, "ASCII") == 0)
        return ascii_string_type;

    if (strcmp(encoding, "Latin-1") == 0)
        return latin1_string_type;

    if (strcmp(encoding, "UTF-8") == 0)
        return utf8_string_type;

    if (strcmp(encoding, "None") == 0)
        return string_type;

    return no_type;
}


/*
 * Get the /API/ option flag.
 */
static apiVersionRangeDef *getAPIRange(optFlags *optflgs)
{
    optFlag *of;

    if ((of = getOptFlag(optflgs, "API", api_range_flag)) == NULL)
        return NULL;

    return of->fvalue.aval;
}


/*
 * Return the API range structure and version number corresponding to the
 * given API range.
 */
static apiVersionRangeDef *convertAPIRange(moduleDef *mod, nameDef *name,
        int from, int to)
{
    int index;
    apiVersionRangeDef *avd, **avdp;

    /* Handle the trivial case. */
    if (from == 0 && to == 0)
        return NULL;

    for (index = 0, avdp = &mod->api_ranges; (*avdp) != NULL; avdp = &(*avdp)->next, ++index)
    {
        avd = *avdp;

        if (avd->api_name == name && avd->from == from && avd->to == to)
            return avd;
    }

    /* The new one must be appended so that version numbers remain valid. */
    avd = sipMalloc(sizeof (apiVersionRangeDef));

    avd->api_name = name;
    avd->from = from;
    avd->to = to;
    avd->index = index;

    avd->next = NULL;
    *avdp = avd;

    return avd;
}


/*
 * Return the style of keyword argument support for a signature.
 */
static KwArgs keywordArgs(moduleDef *mod, optFlags *optflgs, signatureDef *sd,
        int need_name)
{
    KwArgs kwargs;
    optFlag *ka_anno, *no_ka_anno;

    /* Get the default. */
    kwargs = mod->kwargs;

    /*
     * Get the possible annotations allowing /KeywordArgs/ to have different
     * types of values.
     */
    ka_anno = findOptFlag(optflgs, "KeywordArgs");
    no_ka_anno = getOptFlag(optflgs, "NoKeywordArgs", bool_flag);

    if (no_ka_anno != NULL)
    {
        if (ka_anno != NULL)
            yyerror("/KeywordArgs/ and /NoKeywordArgs/ cannot both be specified");

        deprecated("/NoKeywordArgs/ is deprecated, use /KeywordArgs=\"None\" instead");

        kwargs = NoKwArgs;
    }
    else if (ka_anno != NULL)
    {
        /* A string value is the non-deprecated type. */
        if (ka_anno->ftype == string_flag)
        {
            kwargs = convertKwArgs(ka_anno->fvalue.sval);
        }
        else
        {
            deprecated("/KeywordArgs/ is deprecated, use /KeywordArgs=\"All\" instead");

            /* Get it again to check the type. */
            ka_anno = getOptFlag(optflgs, "KeywordArgs", bool_flag);
        }
    }

    /* An ellipsis cannot be used with keyword arguments. */
    if (sd->nrArgs > 0 && sd->args[sd->nrArgs - 1].atype == ellipsis_type)
        kwargs = NoKwArgs;

    if (kwargs != NoKwArgs)
    {
        int a, is_name = FALSE;

        /*
         * Mark argument names as being used and check there is at least one.
         */
        for (a = 0; a < sd->nrArgs; ++a)
        {
            argDef *ad = &sd->args[a];

            if (kwargs == OptionalKwArgs && ad->defval == NULL)
                continue;

            if (ad->name != NULL)
            {
                if (need_name || inMainModule())
                    setIsUsedName(ad->name);

                is_name = TRUE;
            }
        }

        if (!is_name)
            kwargs = NoKwArgs;
    }

    return kwargs;
}


/*
 * Extract the version of a string value optionally associated with a
 * particular feature.
 */
static char *convertFeaturedString(char *fs)
{
    while (fs != NULL)
    {
        char *next, *value;

        /* Individual values are ';' separated. */
        if ((next = strchr(fs, ';')) != NULL)
            *next++ = '\0';

        /* Features and values are ':' separated. */
        if ((value = strchr(fs, ':')) == NULL)
        {
            /* This is an unconditional value so just return it. */
            return strip(fs);
        }

        *value++ = '\0';

        if (isEnabledFeature(strip(fs)))
            return strip(value);

        fs = next;
    }

    /* No value was enabled. */
    return NULL;
}


/*
 * Return the stripped version of a string.
 */
static char *strip(char *s)
{
    while (*s == ' ')
        ++s;

    if (*s != '\0')
    {
        char *cp = &s[strlen(s) - 1];

        while (*cp == ' ')
            *cp-- = '\0';
    }

    return s;
}


/*
 * Return TRUE if the given feature is enabled.
 */
static int isEnabledFeature(const char *name)
{
    qualDef *qd;

    if ((qd = findQualifier(name)) == NULL || qd->qtype != feature_qualifier)
        yyerror("No such feature");

    return !excludedFeature(excludedQualifiers, qd);
}


/*
 * Add a property definition to a class.
 */
static void addProperty(sipSpec *pt, moduleDef *mod, classDef *cd,
        const char *name, const char *get, const char *set,
        codeBlock *docstring)
{
    propertyDef *pd;

    checkAttributes(pt, mod, cd, NULL, name, FALSE);

    pd = sipMalloc(sizeof (propertyDef));

    pd->name = cacheName(pt, name);
    pd->get = get;
    pd->set = set;
    appendCodeBlock(&pd->docstring, docstring);
    pd->next = cd->properties;

    cd->properties = pd;

    if (inMainModule())
        setIsUsedName(pd->name);
}


/*
 * Configure a module and return the (possibly new) current module.
 */
static moduleDef *configureModule(sipSpec *pt, moduleDef *module,
        const char *filename, const char *name, int version, int c_module,
        KwArgs kwargs, int use_arg_names, int call_super_init,
        int all_raise_py_exc, const char *def_error_handler,
        codeBlock *docstring, const char *nameshort)
{
    moduleDef *mod;

    /* Check the module hasn't already been defined. */
    for (mod = pt->modules; mod != NULL; mod = mod->next)
        if (mod->fullname != NULL && strcmp(mod->fullname->text, name) == 0)
            yyerror("Module is already defined");

    /*
     * If we are in a container module then create a component module and make
     * it current.
     */
    if (isContainer(module) || module->container != NULL)
    {
        mod = allocModule();

        mod->file = filename;
        mod->container = (isContainer(module) ? module : module->container);

        module = mod;
    }

    setModuleName(pt, module, name);
    module->kwargs = kwargs;
    module->virt_error_handler = def_error_handler;
    module->version = version;
    appendCodeBlock(&module->docstring, docstring);

    if (nameshort != NULL)
        module->nameshort = nameshort;

    if (all_raise_py_exc)
        setAllRaisePyException(module);

    if (use_arg_names)
        setUseArgNames(module);

    if (call_super_init == 0)
        setCallSuperInitNo(module);
    else if (call_super_init > 0)
        setCallSuperInitYes(module);

    if (pt->genc < 0)
        pt->genc = c_module;
    else if (pt->genc != c_module)
        yyerror("Cannot mix C and C++ modules");

    return module;
}


/*
 * Add a Python naming rule to a module.
 */
static void addAutoPyName(moduleDef *mod, const char *remove_leading)
{
    autoPyNameDef *apnd, **apndp;

    for (apndp = &mod->autopyname; *apndp != NULL; apndp = &(*apndp)->next)
        ;

    apnd = sipMalloc(sizeof (autoPyNameDef));
    apnd->remove_leading = remove_leading;
    apnd->next = *apndp;

    *apndp = apnd;
}


/*
 * Check that no invalid or unknown annotations are given.
 */
static void checkAnnos(optFlags *annos, const char *valid[])
{
    if (parsingCSignature && annos->nrFlags != 0)
    {
        deprecated("Annotations should not be used in explicit C/C++ signatures");
    }
    else
    {
        int i;

        for (i = 0; i < annos->nrFlags; i++)
        {
            const char **name;

            for (name = valid; *name != NULL; ++name)
                if (strcmp(*name, annos->flags[i].fname) == 0)
                    break;

            if (*name == NULL)
                yywarning("Annotation is unknown");
        }
    }
}


/*
 * Check that no annotations were given.
 */
static void checkNoAnnos(optFlags *annos, const char *msg)
{
    if (annos->nrFlags != 0)
        deprecated(msg);
}


/*
 * Handle any /KeepReference/ annotation for a type.
 */
static void handleKeepReference(optFlags *optflgs, argDef *ad, moduleDef *mod)
{
    optFlag *of;

    if ((of = getOptFlag(optflgs, "KeepReference", opt_integer_flag)) != NULL)
    {
        setKeepReference(ad);

        if ((ad->key = of->fvalue.ival) < -1)
            yyerror("/KeepReference/ key cannot be negative");

        /* If there was no explicit key then auto-allocate one. */
        if (ad->key == -1)
            ad->key = mod->next_key--;
    }
}


/*
 * Configure the mapped type annotations that are also valid with mapped type
 * templates.
 */
static void mappedTypeAnnos(mappedTypeDef *mtd, optFlags *optflgs)
{
    if (getOptFlag(optflgs, "NoRelease", bool_flag) != NULL)
        setNoRelease(mtd);

    if (getAllowNone(optflgs))
        setHandlesNone(mtd);

    mtd->doctype = getDocType(optflgs);
    getTypeHints(optflgs, &mtd->typehint_in, &mtd->typehint_out);
    mtd->typehint_value = getTypeHintValue(optflgs);
}


/*
 * Initialise an argument with the derefences of another, plus a new one.
 */
static void add_new_deref(argDef *new, argDef *orig, int isconst)
{
    if ((new->nrderefs = orig->nrderefs + 1) >= MAX_NR_DEREFS)
        yyerror("Internal error - increase the value of MAX_NR_DEREFS");

    memcpy(&new->derefs[0], &orig->derefs[0], sizeof (new->derefs));
    new->derefs[orig->nrderefs] = isconst;
}


/*
 * Add the dereferences from one type to another.
 */
static void add_derefs(argDef *dst, argDef *src)
{
    int i;

    for (i = 0; i < src->nrderefs; ++i)
    {
        if (dst->nrderefs >= MAX_NR_DEREFS - 1)
            fatal("Internal error - increase the value of MAX_NR_DEREFS\n");

        dst->derefs[dst->nrderefs++] = src->derefs[i];
    }
}


/*
 * Check if a word is a Python keyword (or has been at any time).
 */
int isPyKeyword(const char *word)
{
    static const char *kwds[] = {
        "False", "None", "True", "and", "as", "assert", "break", "class",
        "continue", "def", "del", "elif", "else", "except", "finally", "for",
        "from", "global", "if", "import", "in", "is", "lambda", "nonlocal",
        "not", "or", "pass", "raise", "return", "try", "while", "with'"
        "yield",
        /* Historical keywords. */
        "exec", "print",
        NULL
    };

    const char **kwd;

    for (kwd = kwds; *kwd != NULL; ++kwd)
        if (strcmp(*kwd, word) == 0)
            return TRUE;

    return FALSE;
}


/*
 * Check there is nothing after an ellipsis.
 */
static void checkEllipsis(signatureDef *sd)
{
    int a;

    for (a = 0; a < sd->nrArgs; ++a)
        if (sd->args[a].atype == ellipsis_type && a < sd->nrArgs - 1)
            yyerror("An ellipsis must be at the end of the argument list if /NoArgParser/ is not specified");
}

