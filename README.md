Semantic machine memory
=======================

Usage:
------

**smm** *mode* *command* *[arguments]*

where:
*mode* is either "root", "body"

Supported operations:
---------------------

- smm init

- smm path \<path\>
- smm ls \<path\>
- smm mkdir \<path\>
- smm rm \<path\[/name\]\>
- smm cp \<src\[/name\]\> \<dest\[/name\]\>
- smm mv \<src\[/name\]\> \<dest\[/name\]\>
- smm new \<path/name\>

- smm params-of \<path/name\> path
- smm data-of \<path/name\> path

- smm body-of \<path/name\> path \<path\>
- smm body-of \<path/name\> ls \<path\>
- smm body-of \<path/name\> mkdir \<path\>
- smm body-of \<path/name\> rm \<path\[/name\]\>
- smm body-of \<path/name\> cp \<src\[/name\]\> \<dest\[/name\]\>
- smm body-of \<path/name\> mv \<src\[/name\]\> \<dest\[/name\]\>
- smm body-of \<path/name\> new \<path/name\> of \<path/name\>

- smm body-of \<path/name\> appl-of \<path/name\> prototype path
- smm body-of \<path/name\> appl-of \<path/name\> args path

