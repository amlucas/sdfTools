.. _user-tutorials:

.. role:: console(code)
   :language: console

Examples
########

Here we show a few simple examples on how to use ``sdfTools``.

A Sphere...
***********

Create the SDF of a single sphere in the middle of a domain:

.. literalinclude:: ../../../tests/tuto/sphere.py
   :name: sphere-py
   :caption: `sphere.py`

The above script can be run by typing

.. code-block:: bash

    python3 sphere.py

The resulting files ``sphere.bov`` and ``sphere.values`` can be visualiszed with
`visit <https://wci.llnl.gov/simulation/computer-codes/visit>`_.

.. figure:: ../images/sphere.png
    :figclass: align-center
    :width: 90%

    Isosurfaces of the sphere SDF obtained from :ref:`sphere-py`.
