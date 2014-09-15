#ifndef ATOM_INCLUDED
#define ATOM_INCLUDED

extern       in    Atom_length(const char *str);
extern const char *Atom_new   (const char *str, int len);
extern const char *Atom_string(const char *str);
extern const char *Atom_in    (long n);

#endif
