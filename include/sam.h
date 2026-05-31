#ifndef _SAM_
#define _SAM_


#if	defined(__SAMD11C14A__) || defined(__ATSAMD11C14A__) || \
	defined(__SAMD11D14AM__) || defined(__ATSAMD11D14AM__) || \
	defined(__SAMD11D14AS__) || defined(__ATSAMD11D14AS__) || \
	defined(__SAMD11D14AU__) || defined(__ATSAMD11D14AU__)
  #include "samd11/samd11.h"
#elif   defined(__SAMD21E15A__) || defined(__ATSAMD21E15A__) || \
	defined(__SAMD21E16A__) || defined(__ATSAMD21E16A__) || \
	defined(__SAMD21E17A__) || defined(__ATSAMD21E17A__) || \
	defined(__SAMD21E18A__) || defined(__ATSAMD21E18A__) || \
	defined(__SAMD21G15A__) || defined(__ATSAMD21G15A__) || \
	defined(__SAMD21G16A__) || defined(__ATSAMD21G16A__) || \
	defined(__SAMD21G17A__) || defined(__ATSAMD21G17A__) || \
	defined(__SAMD21G17AU__) || defined(__ATSAMD21G17AU__) || \
	defined(__SAMD21G18A__) || defined(__ATSAMD21G18A__) || \
	defined(__SAMD21G18AU__) || defined(__ATSAMD21G18AU__) || \
	defined(__SAMD21J15A__) || defined(__ATSAMD21J15A__) || \
	defined(__SAMD21J16A__) || defined(__ATSAMD21J16A__) || \
	defined(__SAMD21J17A__) || defined(__ATSAMD21J17A__) || \
	defined(__SAMD21J18A__) || defined(__ATSAMD21J18A__)
  #include "samd21a/samd21.h"
#else
  #error Library does not support the specified device.
#endif

#endif /* _SAM_ */

