<map version="freeplane 1.8.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="http.h" LOCALIZED_STYLE_REF="AutomaticLayout.level.root" FOLDED="false" ID="ID_612806407" CREATED="1618490503016" MODIFIED="1618492840971" HGAP_QUANTITY="-61.74999774247414 pt" VSHIFT_QUANTITY="185.24999447911992 pt">
<edge STYLE="bezier" COLOR="#dddd00" WIDTH="thin" DASH="SOLID"/>
<hook NAME="MapStyle" background="#3c3f41" zoom="0.909">
    <properties edgeColorConfiguration="#808080ff,#00ddddff,#dddd00ff,#dd0000ff,#00dd00ff,#dd0000ff,#7cddddff,#dddd7cff,#dd7cddff,#7cdd7cff,#dd7c7cff,#7c7cddff" show_icon_for_attributes="true" show_note_icons="true" fit_to_viewport="false"/>

<map_styles>
<stylenode LOCALIZED_TEXT="styles.root_node" STYLE="oval" UNIFORM_SHAPE="true" VGAP_QUANTITY="24.0 pt">
<font SIZE="24"/>
<stylenode LOCALIZED_TEXT="styles.predefined" POSITION="right" STYLE="bubble">
<stylenode LOCALIZED_TEXT="default" ICON_SIZE="12.0 pt" COLOR="#cccccc" STYLE="fork">
<font NAME="SansSerif" SIZE="10" BOLD="false" ITALIC="false"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.details"/>
<stylenode LOCALIZED_TEXT="defaultstyle.attributes">
<font SIZE="9"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.note" COLOR="#cccccc" BACKGROUND_COLOR="#3c3f41" TEXT_ALIGN="LEFT"/>
<stylenode LOCALIZED_TEXT="defaultstyle.floating">
<edge STYLE="hide_edge"/>
<cloud COLOR="#f0f0f0" SHAPE="ROUND_RECT"/>
</stylenode>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.user-defined" POSITION="right" STYLE="bubble">
<stylenode LOCALIZED_TEXT="styles.topic" COLOR="#18898b" STYLE="fork">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.subtopic" COLOR="#cc3300" STYLE="fork">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.subsubtopic" COLOR="#669900">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.important">
<icon BUILTIN="yes"/>
</stylenode>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.AutomaticLayout" POSITION="right" STYLE="bubble">
<stylenode LOCALIZED_TEXT="AutomaticLayout.level.root" COLOR="#dddddd" STYLE="oval" SHAPE_HORIZONTAL_MARGIN="10.0 pt" SHAPE_VERTICAL_MARGIN="10.0 pt">
<font SIZE="18"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,1" COLOR="#ff3300">
<font SIZE="16"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,2" COLOR="#ffb439">
<font SIZE="14"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,3" COLOR="#99ffff">
<font SIZE="12"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,4" COLOR="#bbbbbb">
<font SIZE="10"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,5"/>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,6"/>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,7"/>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,8"/>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,9"/>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,10"/>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,11"/>
</stylenode>
</stylenode>
</map_styles>
</hook>
<hook NAME="AutomaticEdgeColor" COUNTER="2" RULE="ON_BRANCH_CREATION"/>
<node TEXT="structs" POSITION="left" ID="ID_1524084504" CREATED="1618490711931" MODIFIED="1618491722025" HGAP_QUANTITY="-106.74999640136969 pt" VSHIFT_QUANTITY="-26.249999217689055 pt">
<node TEXT="HttpMsg" ID="ID_906085691" CREATED="1618490738770" MODIFIED="1618784010489" HGAP_QUANTITY="-117.2499960884453 pt" VSHIFT_QUANTITY="17.999999463558215 pt">
<node TEXT="firstLine" ID="ID_711843010" CREATED="1618490819857" MODIFIED="1618784010489" HGAP_QUANTITY="-234.24999260157367 pt" VSHIFT_QUANTITY="9.749999709427364 pt">
<node TEXT="msg is a request =&gt; firstLine = StartLine" ID="ID_946635928" CREATED="1618490867304" MODIFIED="1618783846728" HGAP_QUANTITY="-264.249991707504 pt" VSHIFT_QUANTITY="-20.999999374151248 pt">
<node TEXT="Method method" ID="ID_1910222428" CREATED="1618490943615" MODIFIED="1618784059551" HGAP_QUANTITY="-303.2499905452135 pt" VSHIFT_QUANTITY="-25.4999992400408 pt"><richcontent TYPE="DETAILS" HIDDEN="true">

<html>
  <head>
    
  </head>
  <body>
    <p>
      Internal code for request method
    </p>
  </body>
</html>

</richcontent>
</node>
<node TEXT="String url" ID="ID_1284573313" CREATED="1618490957134" MODIFIED="1618783841668" HGAP_QUANTITY="-274.74999139457964 pt" VSHIFT_QUANTITY="-2.220446049250313E-16 pt"/>
<node TEXT="String httpVersion" ID="ID_1667560510" CREATED="1618490969006" MODIFIED="1618783792513" HGAP_QUANTITY="-317.4999901205304 pt" VSHIFT_QUANTITY="20.24999939650299 pt"/>
</node>
<node TEXT="msg is a response =&gt; firstLine = StatusLine" ID="ID_1314536323" CREATED="1618490899792" MODIFIED="1618783835926" HGAP_QUANTITY="-282.9999911487105 pt" VSHIFT_QUANTITY="28.49999915063384 pt">
<node TEXT="String httpVersion" ID="ID_1942905732" CREATED="1618491001733" MODIFIED="1618783808733" HGAP_QUANTITY="-329.4999897629026 pt" VSHIFT_QUANTITY="-19.49999941885473 pt"/>
<node TEXT="StatusCode code" ID="ID_507369751" CREATED="1618491016453" MODIFIED="1618783835924" HGAP_QUANTITY="-322.7499899640682 pt" VSHIFT_QUANTITY="29.2499991282821 pt"><richcontent TYPE="DETAILS" HIDDEN="true">

<html>
  <head>
    
  </head>
  <body>
    <p>
      Refers to <b>internal </b>code, not http status code.
    </p>
  </body>
</html>
</richcontent>
<font BOLD="false"/>
</node>
</node>
</node>
<node TEXT="HashTable headers" ID="ID_882278699" CREATED="1618491087772" MODIFIED="1618783998180" HGAP_QUANTITY="-269.4999915510419 pt" VSHIFT_QUANTITY="47.99999856948857 pt"><richcontent TYPE="DETAILS" HIDDEN="true">

<html>
  <head>
    
  </head>
  <body>
    <p>
      pairs of (headerName, headerText)
    </p>
    <ul>
      <li>
        headerName: holds the String name of the header;
      </li>
      <li>
        headerText: holds the String value of the header
      </li>
    </ul>
  </body>
</html>

</richcontent>
</node>
</node>
<node TEXT="Status" ID="ID_734027195" CREATED="1618490788137" MODIFIED="1618784077461" HGAP_QUANTITY="-86.49999700486669 pt" VSHIFT_QUANTITY="41.999998748302495 pt">
<node TEXT="unsigned code" ID="ID_337180126" CREATED="1618491500997" MODIFIED="1618784072095" HGAP_QUANTITY="-138.9999954402448 pt" VSHIFT_QUANTITY="24.749999262392542 pt"><richcontent TYPE="DETAILS" HIDDEN="true">

<html>
  <head>
    
  </head>
  <body>
    <p>
      actual http code
    </p>
  </body>
</html>
</richcontent>
</node>
<node TEXT="String name" ID="ID_1985336641" CREATED="1618491533235" MODIFIED="1618784083403" HGAP_QUANTITY="-126.99999579787267 pt" VSHIFT_QUANTITY="11.999999642372142 pt"/>
</node>
<node TEXT="Header" ID="ID_647564463" CREATED="1618491617322" MODIFIED="1618491624859" HGAP_QUANTITY="-93.99999678134928 pt" VSHIFT_QUANTITY="76.49999772012241 pt"/>
</node>
<node TEXT="functions" POSITION="left" ID="ID_1868555207" CREATED="1618490728323" MODIFIED="1618783623234" HGAP_QUANTITY="-116.49999611079704 pt" VSHIFT_QUANTITY="12.7499996200204 pt">
<node TEXT="newHttpRequest() -&gt; HttpMsg" ID="ID_577482448" CREATED="1618492075245" MODIFIED="1618783361470" HGAP_QUANTITY="-211.74999327212592 pt" VSHIFT_QUANTITY="-26.99999919533732 pt"/>
<node TEXT="newHttpResponse() -&gt; HttpMsg" ID="ID_405166785" CREATED="1618492138509" MODIFIED="1618492194456" HGAP_QUANTITY="-219.99999302625676 pt" VSHIFT_QUANTITY="0.74999997764826 pt"/>
<node TEXT="destroyHttpMsg(HttpMsg)" ID="ID_1212729790" CREATED="1618492203736" MODIFIED="1618492220439" HGAP_QUANTITY="-189.9999939203264 pt" VSHIFT_QUANTITY="22.499999329447768 pt"/>
<node TEXT="initHttpStructures()" ID="ID_1211273634" CREATED="1618492227092" MODIFIED="1618492434357" HGAP_QUANTITY="-158.49999485909953 pt" VSHIFT_QUANTITY="30.749999083578615 pt">
<arrowlink SHAPE="CUBIC_CURVE" COLOR="#000000" WIDTH="2" TRANSPARENCY="200" FONT_SIZE="9" FONT_FAMILY="SansSerif" DESTINATION="ID_154703735" MIDDLE_LABEL="initializes" STARTINCLINATION="48;-1;" ENDINCLINATION="12;-20;" STARTARROW="NONE" ENDARROW="DEFAULT"/>
<richcontent TYPE="DETAILS" HIDDEN="true">

<html>
  <head>
    
  </head>
  <body>
    <p>
      must be called before all other functions
    </p>
  </body>
</html>
</richcontent>
</node>
<node TEXT="destroyHttpStructures()" ID="ID_305476469" CREATED="1618783276691" MODIFIED="1618783623232" HGAP_QUANTITY="-176.49999432265776 pt" VSHIFT_QUANTITY="26.24999921768906 pt"/>
<node TEXT="newStatus -&gt; Status" ID="ID_78769653" CREATED="1618783329236" MODIFIED="1618783343815" HGAP_QUANTITY="-160.7499947920443 pt" VSHIFT_QUANTITY="17.99999946355821 pt"/>
</node>
<node TEXT="constants" POSITION="left" ID="ID_154703735" CREATED="1618491814847" MODIFIED="1618492448457" HGAP_QUANTITY="-111.24999626725923 pt" VSHIFT_QUANTITY="37.499998882412946 pt">
<node TEXT="String STATUSES[]" ID="ID_38563409" CREATED="1618491823638" MODIFIED="1618784110981" HGAP_QUANTITY="-166.7499946132304 pt" VSHIFT_QUANTITY="-32.99999901652339 pt">
<arrowlink SHAPE="CUBIC_CURVE" COLOR="#000000" WIDTH="2" TRANSPARENCY="200" FONT_SIZE="9" FONT_FAMILY="SansSerif" DESTINATION="ID_507369751" MIDDLE_LABEL="indexed by" STARTINCLINATION="-88;-20;" ENDINCLINATION="-296;66;" STARTARROW="NONE" ENDARROW="DEFAULT"/>
</node>
<node TEXT="String HEADER_NAMES[]" ID="ID_1260002315" CREATED="1618491843005" MODIFIED="1618784096709" HGAP_QUANTITY="-187.74999398738163 pt" VSHIFT_QUANTITY="5.249999843537812 pt">
<arrowlink SHAPE="CUBIC_CURVE" COLOR="#000000" WIDTH="2" TRANSPARENCY="200" FONT_SIZE="9" FONT_FAMILY="SansSerif" DESTINATION="ID_647564463" MIDDLE_LABEL="indexed by" STARTINCLINATION="107;20;" ENDINCLINATION="323;0;" STARTARROW="NONE" ENDARROW="DEFAULT"/>
</node>
<node TEXT="HashTable METHODS" ID="ID_1874441262" CREATED="1618491904837" MODIFIED="1618783609242" HGAP_QUANTITY="-180.24999421089905 pt" VSHIFT_QUANTITY="25.4999992400408 pt"><richcontent TYPE="DETAILS" HIDDEN="true">

<html>
  <head>
    
  </head>
  <body>
    <p>
      holds pairs (MethodName, Method). This is useful when we know String name of method, and we want to know internal code for such method.
    </p>
  </body>
</html>

</richcontent>
</node>
</node>
</node>
</map>
