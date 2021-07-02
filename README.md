https://miro.com/app/board/o9J_l-Ka3TA=/

Shared Pointer explained:
https://www.youtube.com/watch?v=-dREJCf2ve4
0. shared_ptr is a smart pointer which can share the ownership of object (managed object).
1. Several shared_ptr can point to the same object (managed object).
2. It keep a reference count to maintain how many shared_ptr are pointing to the same object.
    sp0 = new ; sp1 = spo; sp2 = sp0; sp3 = sp1 ... etc
   and once last shared_ptr goes out of scope then the managed object gets deleted automatically.
3. shared_ptr is threads safe and not thread safe. Important for multi threading !!
   a. control block is thread safe
   b. managed object is not ! You need to make it thread safe yourself !
4. There are three ways shared_ptr will destroy managed object.
   a. If the last shared_ptr goes out of scope.
   b. If you initialize shared_ptr with some other shared_ptr.
   c. If you reset shared_ptr.
5. Reference count doesn't work when we use reference or pointer of shared_ptr. IMPORTANT !

// NeedFix: Check that all shared pointers are used correctly and thread safe !

sp.use_count() to get usage counter of shared pointer

MultiThreading:
https://youtu.be/dcSsjxhazu0
https://youtu.be/Hx0BcXd86iA
https://youtu.be/ZROGScvpGrs

subclass (base class) method overriding:
https://en.wikipedia.org/wiki/Method_overriding

NeedFiX:

- Fix coordinate system ?
- Change RGBColorBuffer to RGNA8888 buffer in ViewPlane . Use that one in GUIViewPlane
- I should use namespace
- GFA needs to be operator expanded
