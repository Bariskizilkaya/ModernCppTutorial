// stdafx.h: dosyaları içeren standart sistem için dosya içeriyor,
// sistem ekleme dosyaları ya da projeye özgü ekleme
// dosyaları için ekleme dosyası
//

#ifndef STDAFX_H // eski ve taşınabilir usul header koruması. Derleyici header dosyasını defalarca 
#define STDAFX_H // dahil etmesini önler. Büyük projelerde önemli sorun teşkil ediyor.

#ifdef _MSC_VER
#pragma once
#endif
// Sadece başlık dosyalarını düzenliyorum.
// Sonra bu dosyaya daha dokunmayacağım.
#include "stdheaders.h"
#include "customHeaders.h"

//#include "PointlerFonksiyonlar.h"

// TODO: programınızın burada gerektirdiği ek üstbilgilere başvurun

#endif  // HEADER_FILE