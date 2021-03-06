nildb
======

NIL Key/Value database

NILDB is about the simplest key/value store you'll ever see, anywhere.
It's written in plain vanilla C using only the standard string and FILE
I/O functions, and should port to just about anything with a disk or
something that acts like one.

NILDB is based on [KISSDB](https://github.com/adamierymenko/kissdb), with significant 
update to reduce file size and improve efficiency, and also added the capability to 
delete entries.

It stores keys and values of fixed length in a stupid-simple file format
based on fixed-size hash tables. If a hash collision occurrs, a link list
is created and the entry is appended to the database.  You can add, update, 
lookup and delete. 

Hash table size is a space/speed trade-off parameter. Larger hash tables
will reduce collisions and speed things up a bit, at the expense of memory
and disk space. A good size is usually about 1/2 the average number of
entries you expect.

Features:

 * Tiny
 * Almost zero memory footprint 
 * Very space-efficient on disk 
 * Pretty respectably fast, especially given its simplicity
 * 64-bit file size limit is 2^64 bytes, and 2^32 offset limit between the same hashed entries.
 * Ports to anything with a C compiler and stdlib/stdio
 * Public domain
 * Works cross big-endian and little-endian system.

Limitations:

 * Fixed-size keys and values, must recreate and copy to change any init size parameter
   (Although can be adapted to varied value size easily)
 * No search for subsets of keys/values 
 * No indexes
 * No transactions
 * No special recovery features if a database gets corrupted
 * No built-in thread-safety (guard it with a mutex in MT code)
 * No built-in caching of data (use filesystem cache)

Alternative key/value stores and embedded databases:

 * [KISSDB]( https://github.com/adamierymenko/kissdb) The base of this project, uses multiple hash tables instead of just one
 * [LMDB](http://symas.com/mdb/) uses mmap() and is very fast (not quite as tiny/simple/portable)
 * [CDB](http://cr.yp.to/cdb.html) is also minimal and fast, but has a 4gb size limit
 * [Kyoto Cabinet](http://fallabs.com/kyotocabinet/) is very fast, full-featured, and modern (license required for commercial use)
 * [tdbm](http://tdbm.dss.ca/) a simple, high-performance database with nested atomic transactions
 * [LevelDB](https://github.com/google/leveldb) a fast key-value storage library written at Google that provides an ordered mapping from string keys to string values.
 * [tdb](https://www.samba.org/ftp/tdb/) From Samba group
 * [mdbm](https://github.com/yahoo/mdbm) a very fast memory-mapped key/value store, from Yahoo
 * [boltdb](https://github.com/boltdb/bolt) a golang key/value store
 * [Rocksdb](http://rocksdb.org/) A persistent key-value store for fast storage environments, from Facebook
 * Others: GDBM, NDBM, Berkeley DB, [Wikipedia DBM](https://en.wikipedia.org/wiki/Dbm)
 * [Discussion on Reddit](https://news.ycombinator.com/item?id=8733017)





NILDB is in the public domain as according to the [Creative Commons Public Domain Dedication](http://creativecommons.org/publicdomain/zero/1.0/).

Author: Tiebing Zhang, Circle Media Inc; Adam Ierymenko / ZeroTier Networks LLC
