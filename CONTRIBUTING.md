# Contributing

There are two branches:

* `generator`, containing the latest version of the XML header definitions and relevant generation scripts,
* `main`, containing the latest version of the development libraries.

Changes to the library source code (`library/`) which are not derived from automatic generation should be pushed
to the `main` branch only. Changes to the XML header definitions and scripts should be pushed to the `generator`
branch, which is then merged with the `main` branch periodically.

