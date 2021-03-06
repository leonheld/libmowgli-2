/*
 * Copyright (C) 2005-2008 William Pitcock, et al.
 * Rights to this code are as documented in doc/LICENSE.
 *
 * Config file parser.
 */

#ifndef MOWGLI_SRC_LIBMOWGLI_EXT_CONFPARSE_H_INCLUDE_GUARD
#define MOWGLI_SRC_LIBMOWGLI_EXT_CONFPARSE_H_INCLUDE_GUARD 1

typedef struct _mowgli_configfile mowgli_config_file_t;
typedef struct _mowgli_configentry mowgli_config_file_entry_t;

struct _mowgli_configfile
{
	char *filename;
	mowgli_config_file_entry_t *entries;
	mowgli_config_file_t *next;
	int curline;
	char *mem;
};

struct _mowgli_configentry
{
	mowgli_config_file_t *fileptr;

	int varlinenum;
	char *varname;
	char *vardata;
	int sectlinenum;/* line containing closing brace */

	mowgli_config_file_entry_t *entries;
	mowgli_config_file_entry_t *prevlevel;
	mowgli_config_file_entry_t *next;
};

/* confp.c */
extern void mowgli_config_file_free(mowgli_config_file_t *cfptr);
extern mowgli_config_file_t *mowgli_config_file_load(const char *filename);

#endif /* MOWGLI_SRC_LIBMOWGLI_EXT_CONFPARSE_H_INCLUDE_GUARD */
