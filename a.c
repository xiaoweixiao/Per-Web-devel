g++ -o httpserver httpserver.cc -lpthread
In file included from /usr/include/c++/4.8.2/unordered_map:35:0,
                 from protocolutil.hpp:8,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/c++0x_warning.h:32:2: error: #error This file requires compiler and library support for the ISO C++ 2011 standard. This support is currently experimental, and must be enabled with the -std=c++11 or -std=gnu++11 compiler options.
 #error This file requires compiler and library support for the \
  ^
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:28:29: error: ‘std::unordered_map’ has not been declared
     static void MakeKV(std::unordered_map<std::string,std::string> &kv_,std::string &str_)
                             ^
protocolutil.hpp:28:42: error: expected ‘,’ or ‘...’ before ‘<’ token
     static void MakeKV(std::unordered_map<std::string,std::string> &kv_,std::string &str_)
                                          ^
protocolutil.hpp: In static member function ‘static void ProtocolUtil::MakeKV(int)’:
protocolutil.hpp:30:28: error: ‘str_’ was not declared in this scope
         std::size_t pos_ = str_.find(": ");
                            ^
protocolutil.hpp:38:35: error: ‘kv_insert’ was not declared in this scope
         kv_insert(make_pair(k_,v_));
                                   ^
protocolutil.hpp: At global scope:
protocolutil.hpp:75:5: error: ‘unordered_map’ in namespace ‘std’ does not name a type
     std::unordered_map<std::string,std::string> head_kv;
     ^
protocolutil.hpp: In member function ‘bool Request::RequestHeadParse()’:
protocolutil.hpp:137:38: error: ‘head_kv’ was not declared in this scope
                 ProtocolUtil::MakeKV(head_kv,sub_string_);
                                      ^
protocolutil.hpp: In member function ‘int Request::GetContentLength()’:
protocolutil.hpp:147:27: error: ‘head_kv’ was not declared in this scope
         std::string cl_ = head_kv["Content-Length"];
                           ^
protocolutil.hpp: In member function ‘void Connect::RecvRequestHead(std::string&)’:
protocolutil.hpp:257:25: error: no match for ‘operator!=’ (operand types are ‘std::string {aka std::basic_string<char>}’ and ‘char’)
             while(line_ != '\n')
                         ^
protocolutil.hpp:257:25: note: candidates are:
In file included from /usr/include/c++/4.8.2/bits/locale_facets.h:48:0,
                 from /usr/include/c++/4.8.2/bits/basic_ios.h:37,
                 from /usr/include/c++/4.8.2/ios:44,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from protocolutil.hpp:4,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/streambuf_iterator.h:210:5: note: template<class _CharT, class _Traits> bool std::operator!=(const std::istreambuf_iterator<_CharT, _Traits>&, const std::istreambuf_iterator<_CharT, _Traits>&)
     operator!=(const istreambuf_iterator<_CharT, _Traits>& __a,
     ^
/usr/include/c++/4.8.2/bits/streambuf_iterator.h:210:5: note:   template argument deduction/substitution failed:
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:257:28: note:   ‘std::string {aka std::basic_string<char>}’ is not derived from ‘const std::istreambuf_iterator<_CharT, _Traits>’
             while(line_ != '\n')
                            ^
In file included from /usr/include/c++/4.8.2/string:52:0,
                 from /usr/include/c++/4.8.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.8.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.8.2/ios:42,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from protocolutil.hpp:4,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/basic_string.h:2556:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator!=(const std::basic_string<_CharT, _Traits, _Alloc>&, const _CharT*)
     operator!=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^
/usr/include/c++/4.8.2/bits/basic_string.h:2556:5: note:   template argument deduction/substitution failed:
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:257:28: note:   mismatched types ‘const _CharT*’ and ‘char’
             while(line_ != '\n')
                            ^
In file included from /usr/include/c++/4.8.2/string:52:0,
                 from /usr/include/c++/4.8.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.8.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.8.2/ios:42,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from protocolutil.hpp:4,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/basic_string.h:2544:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator!=(const _CharT*, const std::basic_string<_CharT, _Traits, _Alloc>&)
     operator!=(const _CharT* __lhs,
     ^
/usr/include/c++/4.8.2/bits/basic_string.h:2544:5: note:   template argument deduction/substitution failed:
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:257:28: note:   mismatched types ‘const _CharT*’ and ‘std::basic_string<char>’
             while(line_ != '\n')
                            ^
In file included from /usr/include/c++/4.8.2/string:52:0,
                 from /usr/include/c++/4.8.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.8.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.8.2/ios:42,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from protocolutil.hpp:4,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/basic_string.h:2532:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator!=(const std::basic_string<_CharT, _Traits, _Alloc>&, const std::basic_string<_CharT, _Traits, _Alloc>&)
     operator!=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^
/usr/include/c++/4.8.2/bits/basic_string.h:2532:5: note:   template argument deduction/substitution failed:
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:257:28: note:   mismatched types ‘const std::basic_string<_CharT, _Traits, _Alloc>’ and ‘char’
             while(line_ != '\n')
                            ^
In file included from /usr/include/c++/4.8.2/string:41:0,
                 from /usr/include/c++/4.8.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.8.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.8.2/ios:42,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from protocolutil.hpp:4,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/allocator.h:143:5: note: template<class _Tp> bool std::operator!=(const std::allocator<_CharT>&, const std::allocator<_CharT>&)
     operator!=(const allocator<_Tp>&, const allocator<_Tp>&)
     ^
/usr/include/c++/4.8.2/bits/allocator.h:143:5: note:   template argument deduction/substitution failed:
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:257:28: note:   ‘std::string {aka std::basic_string<char>}’ is not derived from ‘const std::allocator<_CharT>’
             while(line_ != '\n')
                            ^
In file included from /usr/include/c++/4.8.2/string:41:0,
                 from /usr/include/c++/4.8.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.8.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.8.2/ios:42,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from protocolutil.hpp:4,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/allocator.h:138:5: note: template<class _T1, class _T2> bool std::operator!=(const std::allocator<_CharT>&, const std::allocator<_T2>&)
     operator!=(const allocator<_T1>&, const allocator<_T2>&)
     ^
/usr/include/c++/4.8.2/bits/allocator.h:138:5: note:   template argument deduction/substitution failed:
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:257:28: note:   ‘std::string {aka std::basic_string<char>}’ is not derived from ‘const std::allocator<_CharT>’
             while(line_ != '\n')
                            ^
In file included from /usr/include/c++/4.8.2/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/4.8.2/bits/char_traits.h:39,
                 from /usr/include/c++/4.8.2/ios:40,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from protocolutil.hpp:4,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/stl_iterator.h:353:5: note: template<class _IteratorL, class _IteratorR> bool std::operator!=(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_IteratorR>&)
     operator!=(const reverse_iterator<_IteratorL>& __x,
     ^
/usr/include/c++/4.8.2/bits/stl_iterator.h:353:5: note:   template argument deduction/substitution failed:
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:257:28: note:   ‘std::string {aka std::basic_string<char>}’ is not derived from ‘const std::reverse_iterator<_Iterator>’
             while(line_ != '\n')
                            ^
In file included from /usr/include/c++/4.8.2/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/4.8.2/bits/char_traits.h:39,
                 from /usr/include/c++/4.8.2/ios:40,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from protocolutil.hpp:4,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/stl_iterator.h:303:5: note: template<class _Iterator> bool std::operator!=(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)
     operator!=(const reverse_iterator<_Iterator>& __x,
     ^
/usr/include/c++/4.8.2/bits/stl_iterator.h:303:5: note:   template argument deduction/substitution failed:
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:257:28: note:   ‘std::string {aka std::basic_string<char>}’ is not derived from ‘const std::reverse_iterator<_Iterator>’
             while(line_ != '\n')
                            ^
In file included from /usr/include/c++/4.8.2/bits/stl_algobase.h:64:0,
                 from /usr/include/c++/4.8.2/bits/char_traits.h:39,
                 from /usr/include/c++/4.8.2/ios:40,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from protocolutil.hpp:4,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/stl_pair.h:227:5: note: template<class _T1, class _T2> bool std::operator!=(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)
     operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
     ^
/usr/include/c++/4.8.2/bits/stl_pair.h:227:5: note:   template argument deduction/substitution failed:
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:257:28: note:   ‘std::string {aka std::basic_string<char>}’ is not derived from ‘const std::pair<_T1, _T2>’
             while(line_ != '\n')
                            ^
In file included from /usr/include/c++/4.8.2/iosfwd:40:0,
                 from /usr/include/c++/4.8.2/ios:38,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from protocolutil.hpp:4,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/postypes.h:221:5: note: template<class _StateT> bool std::operator!=(const std::fpos<_StateT>&, const std::fpos<_StateT>&)
     operator!=(const fpos<_StateT>& __lhs, const fpos<_StateT>& __rhs)
     ^
/usr/include/c++/4.8.2/bits/postypes.h:221:5: note:   template argument deduction/substitution failed:
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:257:28: note:   ‘std::string {aka std::basic_string<char>}’ is not derived from ‘const std::fpos<_StateT>’
             while(line_ != '\n')
                            ^
In file included from /usr/include/c++/4.8.2/x86_64-redhat-linux/bits/c++allocator.h:33:0,
                 from /usr/include/c++/4.8.2/bits/allocator.h:46,
                 from /usr/include/c++/4.8.2/string:41,
                 from /usr/include/c++/4.8.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.8.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.8.2/ios:42,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from protocolutil.hpp:4,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/ext/new_allocator.h:144:5: note: template<class _Tp> bool __gnu_cxx::operator!=(const __gnu_cxx::new_allocator<_Tp>&, const __gnu_cxx::new_allocator<_Tp>&)
     operator!=(const new_allocator<_Tp>&, const new_allocator<_Tp>&)
     ^
/usr/include/c++/4.8.2/ext/new_allocator.h:144:5: note:   template argument deduction/substitution failed:
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:257:28: note:   ‘std::string {aka std::basic_string<char>}’ is not derived from ‘const __gnu_cxx::new_allocator<_Tp>’
             while(line_ != '\n')
                            ^
In file included from /usr/include/c++/4.8.2/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/4.8.2/bits/char_traits.h:39,
                 from /usr/include/c++/4.8.2/ios:40,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from protocolutil.hpp:4,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/stl_iterator.h:823:5: note: template<class _Iterator, class _Container> bool __gnu_cxx::operator!=(const __gnu_cxx::__normal_iterator<_Iterator, _Container>&, const __gnu_cxx::__normal_iterator<_Iterator, _Container>&)
     operator!=(const __normal_iterator<_Iterator, _Container>& __lhs,
     ^
/usr/include/c++/4.8.2/bits/stl_iterator.h:823:5: note:   template argument deduction/substitution failed:
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:257:28: note:   ‘std::string {aka std::basic_string<char>}’ is not derived from ‘const __gnu_cxx::__normal_iterator<_Iterator, _Container>’
             while(line_ != '\n')
                            ^
In file included from /usr/include/c++/4.8.2/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/4.8.2/bits/char_traits.h:39,
                 from /usr/include/c++/4.8.2/ios:40,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from protocolutil.hpp:4,
                 from httpserver.hpp:4,
                 from httpserver.cc:1:
/usr/include/c++/4.8.2/bits/stl_iterator.h:817:5: note: template<class _IteratorL, class _IteratorR, class _Container> bool __gnu_cxx::operator!=(const __gnu_cxx::__normal_iterator<_IteratorL, _Container>&, const __gnu_cxx::__normal_iterator<_IteratorR, _Container>&)
     operator!=(const __normal_iterator<_IteratorL, _Container>& __lhs,
     ^
/usr/include/c++/4.8.2/bits/stl_iterator.h:817:5: note:   template argument deduction/substitution failed:
In file included from httpserver.hpp:4:0,
                 from httpserver.cc:1:
protocolutil.hpp:257:28: note:   ‘std::string {aka std::basic_string<char>}’ is not derived from ‘const __gnu_cxx::__normal_iterator<_IteratorL, _Container>’
             while(line_ != '\n')
                            ^
make: *** [httpserver] Error 1
