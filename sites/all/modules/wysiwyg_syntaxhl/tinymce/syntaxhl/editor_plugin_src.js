/**
 * Copied from tinymce example plugin and modifed to suite my needs.
 *
 * Clifford Meece
 * http://cliffordmeece.com
 * 
 */

 (function() {
  // Load the language file.
  tinymce.PluginManager.requireLangPack('syntaxhl');
  
  tinymce.create('tinymce.plugins.SyntaxHL', {
    /**
		 * Initializes the plugin, this will be executed after the plugin has been created.
		 * This call is done before the editor instance has finished it's initialization so use the onInit event
		 * of the editor instance to intercept that event.
		 *
		 * @param {tinymce.Editor} ed Editor instance that the plugin is initialized in.
		 * @param {string} url Absolute URL to where the plugin is located.
		 */
    init: function(ed, url) {
      var t = this;
 
      t.editor = ed;
      t.url = url;
      
      function isSyntaxElm(n) {
        return /^(wysiwyg-syntaxhl)/.test(n.className);
      };
      
      // Register the command so that it can be invoked by using tinyMCE.activeEditor.execCommand('mceExample');
      ed.addCommand('mceSyntaxHL',
      function() {
        ed.windowManager.open({
          file: url + '/dialog.php?path=' + escape(tinyMCE.baseURL) + '&random=' + Math.random(),
          width: 450 + parseInt(ed.getLang('syntaxhl.delta_width', 0)),
          height: 400 + parseInt(ed.getLang('syntaxhl.delta_height', 0)),
          inline: 1
        },
        {
          plugin_url: url
          // Plugin absolute URL
        });
      });

      // Register button
      ed.addButton('syntaxhl', {
        title: 'syntaxhl.desc',
        cmd: 'mceSyntaxHL',
        image: url + '/img/highlight.gif'
      });

      // Add a node change handler, selects the button in the UI when a <pre> element is selected
      ed.onNodeChange.add(function(ed, cm, n) {
        var style = ed.dom.getAttrib(n, 'class');
        cm.setActive('syntaxhl', n.nodeName == 'PRE' && style.match(/wysiwyg-syntaxhl/));
      });

      // Fixme not all pre tags or even any pre tags
      ed.onInit.add(function() {
        if (ed && ed.plugins.contextmenu) {
          ed.plugins.contextmenu.onContextMenu.add(function(th, m, e) {
            var style = ed.dom.getAttrib(e, 'class');
            if (e.nodeName == 'PRE' && style.match(/wysiwyg-syntaxhl/)) {
              m.add({
                title: 'Edit Code',
                icon: '',
                cmd: 'mceSyntax'
              });
            }
          });
        }
      });
      
      // convert any {}-macro tags to pre's
      //ed.onBeforeSetContent.add(t._macroToPre, t);
      ed.onBeforeSetContent.add(
        function(ed, o) {
          //console.log('before set');
          
          var nlChar;
          if (tinymce.isIE)
            nlChar = '\r\n';
          else
            nlChar = '\n';
            
          o.content = o.content.replace(/(<p>)?(<P>)?{syntaxhighlighter ([^}]*)}/g, '<pre class="wysiwyg-syntaxhl $3">');
          o.content = o.content.replace(/{\/syntaxhighlighter}(<\/p>)?(<\/P>)?/g, '</pre>');
        }
      );
      
      ed.onPostProcess.add(
        function(ed, o) {
          //console.log('doing postprocess');
          if (o.save) {
            if (!tinymce.isIE) {
              // IE is collapsing newlines somewhere, so I only to the pre-to-macro 
              // conversion for non-ie browsers
              
              // This basic regex works, but it would match every non syntaxhl </pre> element
              //o.content = o.content.replace(/<pre class="wysiwyg-syntaxhl ([^"]*)">/g,'{syntaxhighlighter $1}' );
              //o.content = o.content.replace(/<\/pre>/g,'{/syntaxhighlighter}' );
              // better to use dom utilities...
              var syntaxElements = ed.dom.select('pre.wysiwyg-syntaxhl');
              //console.log(syntaxElements);

              for (var i = 0; i < syntaxElements.length; i++) {
                //console.log('in loop');
                //console.log('element:' + syntaxElements[i]);
                //console.log(syntaxElements[i].toString());
                //console.log(syntaxElements[i]);
                //console.log(ed.dom.getOuterHTML(syntaxElements[i]));
                //console.log('element text: '+ t._getText(syntaxElements[i]));
                var style = ed.dom.getAttrib(syntaxElements[i], 'class');

                matchString = ed.dom.getOuterHTML(syntaxElements[i]);
                if (tinymce.isIE) {
                  //console.log('is ie');
                  matchString = matchString.replace(/^<PRE/, '<pre' );
                  matchString = matchString.replace(/PRE>$/, 'pre>' );
                } 
                //console.log('matchString: '+ matchString);
                var start = o.content.indexOf(matchString);
                //var start = o.content.indexOf(t._getText(syntaxElements[i]));
                //console.log('match starts on: ' + start);

                var length = ed.dom.getOuterHTML(syntaxElements[i]).length;
                //var length = t._getText(syntaxElements[i]).length;
                //console.log('length of match is: ' + length );

                style = style.replace(/(wysiwyg-syntaxhl\s*)/g, '');

                // always use the _getText function, because innerHTML causes ie to remove whitespace
                var macroString = '{syntaxhighlighter ' + style + '}' + ed.dom.encode(t._getText(syntaxElements[i])) + '{/syntaxhighlighter}';
                //console.log("macro:" + macroString);

                var startString = o.content.substr(0, start);
                var endString = o.content.substr(start+length);

                if (start != -1) {
                  o.content = startString + macroString + endString;
                } 

                // The below should be all I need, but it doesn't work, which is why I jump through all the hoops above.
                // I suspect it is because at this point in the program flow, using the domutils form the tinyMCE
                // library no longer update o.content, so whatever I need to do, I need to do directly to
                // o.content
                //ed.dom.setOuterHTML(syntaxElements[i], macroString);
              }
            }
          }
        }
      );

      //ed.onSaveContent.add(function(ed, o) {
      //  window.alert('on savecontent');
      //});
    },

    /**
		 * Creates control instances based in the incomming name. This method is normally not
		 * needed since the addButton method of the tinymce.Editor class is a more easy way of adding buttons
		 * but you sometimes need to create more complex controls like listboxes, split buttons etc then this
		 * method can be used to create those.
		 *
		 * @param {String} n Name of the control to create.
		 * @param {tinymce.ControlManager} cm Control manager to use inorder to create new control.
		 * @return {tinymce.ui.Control} New control instance or null if no control was created.
		 */
    createControl: function(n, cm) {
      return null;
    },

    /**
		 * Returns information about the plugin as a name/value array.
		 * The current keys are longname, author, authorurl, infourl and version.
		 *
		 * @return {Object} Name/value array containing information about the plugin.
		 */
    getInfo: function() {
      return {
        longname: 'Syntax Highlighter',
        author: 'Clifford Meece',
        authorurl: 'http://cliffordmeece.com',
        infourl: 'http://drupal.org/project/wysiwyg_syntaxhl',
        version: "1.0"
      };
    },

    _getText: function(obj) {
      // return the data of obj if its a text node
      if (obj.nodeType == 3) return obj.nodeValue;
      var txt = new Array(),
      i = 0;
      // loop over the children of obj and recursively pass them back to this function
      while (obj.childNodes[i]) {
        txt[txt.length] = this._getText(obj.childNodes[i]);
        i++;
      }
      // return the array as a string
      return txt.join("");
    }
  });

  // Register plugin
  tinymce.PluginManager.add('syntaxhl', tinymce.plugins.SyntaxHL);
})();