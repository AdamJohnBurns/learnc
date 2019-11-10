#LearnC

Re-learning the C language from the book Learn C the Hard Way.

## Nano:
* Start with `-m` to enable the mouse cursor.
* Hotkeys generally use the `control` key on mac. This is represented as a ^ character.
* ^G is help
* ^O is save 
* ^X is close
* ^W is find ('Where is the thing?")
* ^C shows line number details on currently selected line
* There doesn't seem to be a way to enable line number display

## git
* List all files in the .git index with `git ls-files`
* Remove an item from the index that's already been added: `git rm --cached <filename>`

## C API

### stdio ###
* fflush(stream) - clear output buffer when writing a file, flushing contents to console (if stdout) or disk (if file stream)
* fwrite(buffer, size, count, stream) - Writes _count_ objects from _buffer_ to _stream_.

### stdlib ###
* free(pointer) - deallocates previously allocated by malloc (etc)
* malloc(size) - allocates _size_ bytes of uninitialized storage, returning pointer to first allocated byte
