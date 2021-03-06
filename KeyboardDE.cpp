/*
  KeyboardDE.cpp

  Copyright (c) 2015, Arduino LLC
  Original code (pre-library): Copyright (c) 2011, Peter Barrett
  
  This version is written by Niels Sedat (2018-06-21)
  ...handle all the available keys on a german keyboard
  eg. üöäÜÖÄß€ ... but also mapping all the special chars as well
  added compatibility for On The Go Porgrammer  /
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "KeyboardDE.h"

#if defined(_USING_HID)

//================================================================================
//================================================================================
//	Keyboard

static const uint8_t _hidReportDescriptor[] PROGMEM = {

  //  Keyboard
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)  // 47
    0x09, 0x06,                    // USAGE (Keyboard)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, 0x02,                    //   REPORT_ID (2)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
   
  0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    
  0x95, 0x08,                    //   REPORT_COUNT (8)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)
    
  0x95, 0x06,                    //   REPORT_COUNT (6)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x65,                    //   LOGICAL_MAXIMUM (101)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
    
  0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0xc0,                          // END_COLLECTION
};

Keyboard_::Keyboard_(void) 
{
	static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
	HID().AppendDescriptor(&node);
}

void Keyboard_::begin(void)
{
}

void Keyboard_::end(void)
{
}

void Keyboard_::sendReport(KeyReport* keys)
{
	HID().SendReport(2,keys,sizeof(KeyReport));
}


extern
const uint8_t _asciimap_iso[256] PROGMEM;

#define SHIFT 0x80
#define ALTGR 0x40
const uint8_t _asciimap_iso[256] =
{
//0...
	0x00,             // NUL
	0x00,             // SOH
	0x00,             // STX
	0x00,             // ETX
	0x00,             // EOT
	0x00,             // ENQ
	0x00,             // ACK  
	0x00,             // BEL
	0x2a,			  // BS	Backspace
	0x2b,			  // TAB	Tab
//10...
	0x28,			  // LF	Enter
	0x00,             // VT 
	0x00,             // FF 
	0x00,             // CR 
	0x00,             // SO 
	0x00,             // SI 
	0x00,             // DEL
	0x00,             // DC1
	0x00,             // DC2
	0x00,             // DC3
//20...
	0x00,             // DC4
	0x00,             // NAK
	0x00,             // SYN
	0x00,             // ETB
	0x00,             // CAN
	0x00,             // EM 
	0x00,             // SUB
	0x00,             // ESC
	0x00,             // FS 
	0x00,             // GS 
//30...
	0x00,             // RS 
	0x00,             // US 
//32...
	0x2c,		   // 32 ' '
	0x1e|SHIFT,	   // !
	0x1f|SHIFT,	   // "
	0x31,          // #
	0x21|SHIFT,    // $
	0x22|SHIFT,    // %
	0x23|SHIFT,    // &
	0x31|SHIFT,    // '
//40...
	0x25|SHIFT,    // 40 (
	0x26|SHIFT,    // )
	0x30|SHIFT,    // *
	0x30,          // +
	0x36,          // ,
	0x38,          // -
	0x37,          // .
	0x24|SHIFT,    // /
	0x27,          // 48 0
	0x1e,          // 1
//50...
	0x1f,          // 50 2
	0x20,          // 3
	0x21,          // 4
	0x22,          // 5
	0x23,          // 6
	0x24,          // 7
	0x25,          // 8
	0x26,          // 9
	0x37|SHIFT,    // :
	0x36|SHIFT,    // ;
//60...
	0x03,          // 60 <
	0x27|SHIFT,    // =
	0x03|SHIFT,    // >
	0x2d|SHIFT,    // ?
	0x14|ALTGR,    // @
	0x04|SHIFT,    // 65 A
	0x05|SHIFT,    // B
	0x06|SHIFT,    // C
	0x07|SHIFT,    // D
	0x08|SHIFT,    // E
//70...
	0x09|SHIFT,    // 70 F
	0x0a|SHIFT,    // G
	0x0b|SHIFT,    // H
	0x0c|SHIFT,    // I
	0x0d|SHIFT,    // J
	0x0e|SHIFT,    // K
	0x0f|SHIFT,    // L
	0x10|SHIFT,    // M
	0x11|SHIFT,    // N
	0x12|SHIFT,    // O
//80...
	0x13|SHIFT,    // 80 P
	0x14|SHIFT,    // Q
	0x15|SHIFT,    // R
	0x16|SHIFT,    // S
	0x17|SHIFT,    // T
	0x18|SHIFT,    // U
	0x19|SHIFT,    // V
	0x1a|SHIFT,    // W
	0x1b|SHIFT,    // X
	0x1d|SHIFT,    // Y
//90...
	0x1c|SHIFT,    // 90 Z
	0x25|ALTGR,    // [
	0x2d|ALTGR,    // bslash
	0x26|ALTGR,    // ]
	0x35,          // ^
	0x38|SHIFT,    // _
	0x2e|SHIFT,    // `
	0x04,          // 97 a
	0x05,          // b
	0x06,          // c
//100...
	0x07,          // 100 d
	0x08,          // e
	0x09,          // f
	0x0a,          // g
	0x0b,          // h
	0x0c,          // i
	0x0d,          // j
	0x0e,          // k
	0x0f,          // l
	0x10,          // m
//110...
	0x11,          // 110 n
	0x12,          // o
	0x13,          // p
	0x14,          // q
	0x15,          // r
	0x16,          // s
	0x17,          // t
	0x18,          // u
	0x19,          // v
	0x1a,          // w
//120...
	0x1b,          // 120 x
	0x1d,          // y
	0x1c,          // z
	0x24|ALTGR,    // {
	0x03|ALTGR,    // |
	0x27|ALTGR,    // }
	0x30|ALTGR,    // 126 ~ (AltGr-+)
	0x2a,          // DEL
//128...
	0x00,             // NUL
	0x00,             // SOH
//130...
	0x00,             // STX
	0x00,             // ETX
	0x00,             // EOT
	0x00,             // ENQ
	0x00,             // ACK  
	0x00,             // BEL
	0x2a,			  // BS	Backspace
	0x2b,			  // TAB	Tab
	0x28,			  // LF	Enter
	0x00,             // VT 
//140...
	0x00,             // FF 
	0x00,             // CR 
	0x00,             // SO 
	0x00,             // SI 
	0x00,             // DEL
	0x00,             // DC1
	0x00,             // DC2
	0x00,             // DC3
	0x00,             // DC4
	0x00,             // NAK
//150...
	0x00,             // SYN
	0x00,             // ETB
	0x00,             // CAN
	0x00,             // EM 
	0x00,             // SUB
	0x00,             // ESC
	0x00,             // FS 
	0x00,             // GS 
	0x00,             // RS 
	0x00,             // US 
//160...
	0x2c|ALTGR,       // nobr
	0x1e|ALTGR|SHIFT, // ¡
	0x06|ALTGR,       // ¢
	0x20|ALTGR|SHIFT, // £
	0,                // currency sign
	0,                // yen sign
	0x03|ALTGR|SHIFT, // ¦
	0x20|SHIFT,       // §
	0x2f|ALTGR,       // "
	0,                // copy
//170...
	0,                // fem
	0,                // left pointing double angle
	0,                // not
	0,                // soft hyphen
	0,                // reg
	0,                // macron
	0x35|SHIFT,       // degree
	0,                // plus-minus
	0x1f|ALTGR,       // super2
	0x20|ALTGR,       // super3
//180...
	0x2e,             // acute ´
	0x10|ALTGR,       // micro µ
	0,                // pilcrow
	0,                // mid dot
	0,                // cedilla
	0,                // super1
	0,                // masc
	0,                // right pointing double angle
	0,                // quarter
	0,                // half
//190...
	0,                // 3 quarter
	0,                // inv questmark
	0,                // À
	0,                // Á
	0,                // Â
	0,                // Ã
	0x34|SHIFT,       // Ä
	0,                // ringA
	0,                // Æ
	0,                // Cedi
//200...
	0,                // È
	0,                // É
	0,                // Ê
	0,                // Ë
	0,                // Ì
	0,                // Í
	0,                // Î
	0,                // Ï
	0,                // Eth
	0,                // Ñ
//210...
	0,                // Ò
	0,                // Ó
	0,                // Ô
	0,                // Õ
	0x33|SHIFT,       // Ö
	0,                // mult
	0,                // Ø
	0,                // Ù
	0,                // Ú
	0,                // Û
//220...
	0x2f|SHIFT,       // Ü
	0,                // Ý
	0,                // Thorn
	0x2d,             // ß
	0,                // à
	0,                // á
	0,                // â
	0,                // ã
	0x34,             // ä
	0,                // å
//230...
	0,                // æ
	0,                // ç
	0,                // è
	0,                // é
	0,                // ê
	0,                // ë
	0,                // ì
	0,                // í
	0,                // î
	0,                // ï
//240...
	0,                // eth
	0,                // ñ
	0,                // ò
	0,                // ó
	0,                // ô
	0,                // õ
	0x33,             // ö
	0,                // div
	0,                // ø
	0,                // ù
//250	
	0,                // ú
	0,                // û
	0x2f,             // 252=0xfc ü
	0x08|ALTGR,       // euro € (Niels!, ALT+e)
	0,                // thorn
	0,                // ÿ
};

uint8_t USBPutChar(uint8_t c);

// press() adds the specified key (iso-8859-1 encoded)
// to the persistent key report and sends the report.  Because of the way 
// USB HID works, the host acts like the key remains pressed until we 
// call release(), releaseAll(), or otherwise clear the report and resend.
size_t Keyboard_::press_iso(uint8_t k) 
{
	uint8_t i;

	k = pgm_read_byte(_asciimap_iso + k);
	if (!k) {
		setWriteError();
		return 0;
	}
	if (k & 0x80) {						// it's a capital letter or other character reached with shift
    _keyReport.modifiers |= 0x02; // the left shift modifier
    k &= 0x7F;
	}
	if (k & 0x40) {
		_keyReport.modifiers |= 0x40;
		k &= 0x3F;
	}
	if (k == 0x03) { // special case 0x64
		k = 0x64;
	}
	
	// Add k to the key report only if it's not already present
	// and if there is an empty slot.
	if (_keyReport.keys[0] != k && _keyReport.keys[1] != k && 
		_keyReport.keys[2] != k && _keyReport.keys[3] != k &&
		_keyReport.keys[4] != k && _keyReport.keys[5] != k) {
		
		for (i=0; i<6; i++) {
			if (_keyReport.keys[i] == 0x00) {
				_keyReport.keys[i] = k;
				break;
			}
		}
		if (i == 6) {
			setWriteError();
			return 0;
		}	
	}
	sendReport(&_keyReport);
	return 1;
}

// release() takes the specified key out of the persistent key report and
// sends the report.  This tells the OS the key is no longer pressed and that
// it shouldn't be repeated any more.
size_t Keyboard_::release_iso(uint8_t k) 
{
	uint8_t i;
	k = pgm_read_byte(_asciimap_iso + k);
	if (!k) {
		return 0;
	}
	if (k & 0x80) {							// it's a capital letter or other character reached with shift
		_keyReport.modifiers &= ~(0x02);	// the left shift modifier
		k &= 0x7F;
	}
	if (k & 0x40) {
		_keyReport.modifiers &= ~(0x40);
		k &= 0x3F;
	}
	if (k == 0x03) { // special case 0x64
		k = 0x64;
	}
	
	// Test the key report to see if k is present.  Clear it if it exists.
	// Check all positions in case the key is present more than once (which it shouldn't be)
	for (i=0; i<6; i++) {
		if (0 != k && _keyReport.keys[i] == k) {
			_keyReport.keys[i] = 0x00;
		}
	}

	sendReport(&_keyReport);
	return 1;
}


// press() adds the specified key (printing, non-printing, or modifier)
// to the persistent key report and sends the report.  Because of the way 
// USB HID works, the host acts like the key remains pressed until we 
// call release(), releaseAll(), or otherwise clear the report and resend.
size_t Keyboard_::press(uint8_t k) 
{
  uint8_t i;
  if (k >= 136) {     // it's a non-printing key (not a modifier)
    k = k - 136;
  } else if (k >= 128) {  // it's a modifier key
    _keyReport.modifiers |= (1<<(k-128));
    k = 0;
  } else {        // it's a printing key
    k = pgm_read_byte(_asciimap_iso + k);
    if (!k) {
      setWriteError();
      return 0;
    }
    if (k & 0x80) {           // it's a capital letter or other character reached with shift
      _keyReport.modifiers |= 0x02; // the left shift modifier
      k &= 0x7F;
    }
  }
  
  // Add k to the key report only if it's not already present
  // and if there is an empty slot.
  if (_keyReport.keys[0] != k && _keyReport.keys[1] != k && 
    _keyReport.keys[2] != k && _keyReport.keys[3] != k &&
    _keyReport.keys[4] != k && _keyReport.keys[5] != k) {
    
    for (i=0; i<6; i++) {
      if (_keyReport.keys[i] == 0x00) {
        _keyReport.keys[i] = k;
        break;
      }
    }
    if (i == 6) {
      setWriteError();
      return 0;
    } 
  }
  sendReport(&_keyReport);
  return 1;
}

// release() takes the specified key out of the persistent key report and
// sends the report.  This tells the OS the key is no longer pressed and that
// it shouldn't be repeated any more.
size_t Keyboard_::release(uint8_t k) 
{
  uint8_t i;
  if (k >= 136) {     // it's a non-printing key (not a modifier)
    k = k - 136;
  } else if (k >= 128) {  // it's a modifier key
    _keyReport.modifiers &= ~(1<<(k-128));
    k = 0;
  } else {        // it's a printing key
    k = pgm_read_byte(_asciimap_iso + k);
    if (!k) {
      return 0;
    }
    if (k & 0x80) {             // it's a capital letter or other character reached with shift
      _keyReport.modifiers &= ~(0x02);  // the left shift modifier
      k &= 0x7F;
    }
  }
  
  // Test the key report to see if k is present.  Clear it if it exists.
  // Check all positions in case the key is present more than once (which it shouldn't be)
  for (i=0; i<6; i++) {
    if (0 != k && _keyReport.keys[i] == k) {
      _keyReport.keys[i] = 0x00;
    }
  }

  sendReport(&_keyReport);
  return 1;
}


void Keyboard_::releaseAll(void)
{
  _keyReport.keys[0] = 0;
  _keyReport.keys[1] = 0; 
  _keyReport.keys[2] = 0;
  _keyReport.keys[3] = 0; 
  _keyReport.keys[4] = 0;
  _keyReport.keys[5] = 0; 
  _keyReport.modifiers = 0;
  sendReport(&_keyReport);
}


// ::write is also used by print and println
size_t Keyboard_::write(uint8_t c)
{
	String cn;
	char c2[2];	// single char buffer

	c2[0] = (c & 0xff);
	c2[1] = 0;
	utf8ascii(c2);
	c = c2[0];

	if (c == 0) {	// utf8 prefix (0xc3) ... wait for next char
		return 1;
	}
	
	uint8_t p = press_iso(c);  // Keydown
	release_iso(c);            // Keyup

	return p;              // just return the result of press() since release() almost always returns 1
}



// ****** UTF8-Decoder: convert UTF8-string to extended ASCII *******
static byte c1;  // Last character buffer


// Convert a single Character from UTF8 to Extended ASCII
// Return "0" if a byte has to be ignored
byte Keyboard_::utf8ascii(byte ascii) {
    if ( ascii < 128 )   // Standard ASCII-set 0..0x7F handling  
    {
		c1 = 0; 
        return (ascii); 
    }

    // get previous input
    byte last = c1;   // get last char
    c1=ascii;         // remember actual character

    switch (last)     // conversion depending on first UTF8-character
    {
		case 0xC2:
			return  (ascii);
			break;
        case 0xC3:
			ascii = (ascii | 0xC0);
			// german umlaut handling
			switch (ascii)	// see http://kellykjones.tripod.com/webtools/ascii_utf8_table.html
			{
				case 0xbc: // uumlaut
					ascii = 0xfc;	// 252
					break;
				case 0xb6: // oumlaut
					ascii = 0xf6;	// 246
					break;
				case 0xe4: // aumlaut
					ascii = 0xe4;	// 228
					break;
				case 0x9f: // szett
					ascii = 0xdf;	// 223
					break;
				case 0x9c: // Uumlaut
					ascii = 0xdc;	// 220
					break;
				case 0x96: // Oumlaut
					ascii = 0xd6;	// 214
					break;
				case 0x84: // Aumlaut
					ascii = 0xc4;	// 196
					break;
				default:
					break;
			}
			return ascii;
			break;
        case 0x82:
			if (ascii == 0xac) {
				return (0xfd);       // special case Euro-symbol
			}
			break;
    }
    return  (0);  // otherwise: return zero, if character has to be ignored
}

// convert String object from UTF8 String to Extended ASCII
String Keyboard_::utf8ascii(String s)
{       
	String r="";
	char c;

	for (int i=0; i<s.length(); i++)
	{
		c = utf8ascii(s.charAt(i));
		if (c!=0) {
			r+=c;
		}
	}

	return r;
}

// In Place conversion UTF8-string to Extended ASCII (ASCII is shorter!)
void Keyboard_::utf8ascii(char* s)
{       
	int k=0;
	char c;

	for (int i=0; i<strlen(s); i++)
	{
		c = utf8ascii(s[i]);
		if (c!=0) {
		   s[k++]=c;
		}
	}
	s[k]=0;
}


Keyboard_ Keyboard;

#endif
