INTRODUCTION
------------
Maintainer:
  Roman Barbun (http://drupal.org/user/66894)

IIP Image module

OVERVIEW
------------

This module provides integration of IIPImage to Drupal.

"IIPImage is an advanced high-performance feature-rich imaging server system for
web-based streamed viewing and zooming of ultra high-resolution images.
It is designed to be fast and bandwidth-efficient with low processor and memory
requirements.
The system can comfortably handle gigapixel size images as well as advanced
image features such as both 8 and 16 bit depths, CIELAB colorimetric images
and scientific imagery such as multispectral images."

Read more: http://iipimage.sourceforge.net/

SETTING UP:
-----------

1) You have to embed Fast CGI module within a host server such as Apache,
   Lighttpd, MyServer or Nginx.
   So, eventually in your root there should be a folder called 'fcgi-bin' with
   'iipsrv.fcgi' file in there.
   You'll find a documentation about installation and setting of FCGI module for
   your server here:
   http://iipimage.sourceforge.net/documentation/server/


2) Create directory "iip_image" in "sites/all/libraries/" and unpack this
   archive:
http://downloads.sourceforge.net/iipimage/iipmooviewer-1.1.tar.gz?use_mirror=ovh

   (It contains IIPMooViewer 1.1 with all the necessary js, css and images.)

3) Install Lightbox2 module.
   TO-DO:
   I was in need to use Lightbox2 for a real project, so there should not
   be any dependency on Lightbox2 in future releases. Anyway, it's easy to look
   at iip_image_output_page() function and use anything you want there instead
   Lightbox2.

   NOTE:
   There's no stable version of Lightbox2 for D7 yet (27/09/2011),
   that's why some useful features are still not working.
   I was expecting to set the box size in percentage, but somehow it wasn't
   implemented yet. So, if you'd like to have this possibility you can apply my
   patch for Lightbox2 here:
   http://drupal.org/node/1287270


4) Install Imagemagick.
   IIP Image module uses ImageMagick software suite to convert images 'from/to'
   tif format. Usually it locates in "/usr/bin/convert".
   ImageMagick needs to be installed on your server and the convert binary needs
   to be accessible and executable from PHP.
   The PHP configuration must allow invocation of proc_open() (which is
   security-wise identical to exec()).
   Consult your server administrator or hosting provider if you are unsure about
   these requirements.

   NOTE: You need to have libtiff library to perform TIF convertion.
   If you haven't got it, please download latest from: http://www.libtiff.org/

IMAGE REQUIREMENTS:
------------------

IIP Server supports only multi-tiled TIFF and JPEG2000 images.
IIP Image module supports ONLY TIFF (.tif extension) because i had browser
troubles when tried to upload jp2 files. Support of JPEG2000 is a to-do for next
releases.
To read more about required images go to:
http://iipimage.sourceforge.net/documentation/images/

USAGE GUIDE:
------------

1) Add an Image field to your content type and choose 'Image for IIP' as widget.

2) Then go edit field and put 'tif' to allowed file extensions
   (in case you need to upload TIFF (.tif) images).
   Also, there you can change TIFF tile size and thumbnail resolution settings.

3) Go to "Manage Display" tab of your content type and choose
   'Image IIP_formatter' as a default formatter.

4) Here you go, make a content and upload your image.
   If the given image is JPG, JPEG, PNG, GIF it will automatically convert it to
   TIFF image to be passed to IIP Server.
   If you upload TIFF (.tif) image, module will convert it to JPEG, while still
   passing the original TIFF to IIP Server.

DEPENDENCIES:
------------
Lightbox2 for comfortable overlay view.

NOTE:
Module will only work for public filesystems. It's still in TO-DO to provide
private filesystems support.
