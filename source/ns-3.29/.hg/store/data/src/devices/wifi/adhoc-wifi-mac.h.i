                	���������]��R�ZMe+z��Y���=+            (�/�`
-( �F�,��n"�	�ȄqB�I����X� ��iS��D�,2A�U�.� � � A��p'G���f�����z��'���vF��֧�^��>WԳ�~<���'<wT)I�<�Ӿ�3$�uڕ�m�p4�?,,D.�)�V����֐�Ԙ��փ��>j��,�.a�U�`���}2`@�~2�?�7��U'���*��í%5�#��k?�Mz	Yp�C���"�ਈC���e �E�!�@�]"�]�5 	�Xhh�:w�[�9��b�<�q�r����stG��TR����E͎�Y���dE�I����yR̝ѩ�p,6�L���Ù6�Ω�x���\$>�1<�%���LND���j�9w��/�Yį��j�>��h&g�8�f�Ǣ��s�x�@�QL�3���nUϗ�b�M��/bR�����N��G�t��L#�����ߓ.��(]��^?�py��c$�g�ʭu�[�'�	RАZ�0|�38#�q�	m��,Y����)�f����<�,�t�k��h<��([�[�Q9����:�
B)���Q���%5Јp~t�Ǧ�%4�Oe�|.��O���2���Nh�IA�gl�vuI� B��к���f.����Ա�!����e�2Mj��9��K��6q�&�c�$f��_Y��Xk��X����q͐��oH?SyѶH���z^mi����q$-��L�E厬�S*c�-��(;\�Ŝ��NQxVm�"5��J5��JH�V{^%�T��p�:[���P�Py���W��6ysGSJ��S�J��n�x-E*|e�o�֠�I.eL9���4J����q�cF�D`�� !  B�#;�A�b��`�  XG r�*�y7�Z(�I���	p�[>��1�TOH)�^�E(��#2��?h�#$�Pw�X��S��2`���tQ���	�cE@AP7;���UqJR�4�f�!U��t�T�HU#*�;*{B���6�'�T�=�&R����EU�1O�?
 ��b���>�`����,��z�F�@d�e� 1
���[���9WB�V)N9/~��ǖN;��P~��,LR/��	��~;b�(4�l�s��`a#���;�n��[�R��|��� ���<Ā��Z'P��M�3d�#��g�4�%ќ�� �p����yl�jף�����x�|�������� �<v��V�{� a1'��/H{�	4�Ԭ|�:��}Z���گf�C�� ��_�'�/�W��r{*>���         -  
�      	�    ������o$m�W��!(�T�݅                   ^      
�  
�     Ptr<MacLow> m_low;
    <     X  
�     
|   �����-��'S�̄]v�ɩ1:1�            (�/� k} �  � ,  // all inherited from WifiMac base class.
  � 'Object VuU����#    �     l  �     
~   ����+�=
�9�ET8��4?o            (�/� � t  | u  virtual Time GetSlot (void) const;
ifsEifsNoD  
� 3 m_sloifse;

 O(��!���<c7�<�q��{pD          b  �     �   ����f����� ��3��d �o���            (�/� c� �  z  �   W  virtual void Enqueue (Ptr<const Packet> p, Mac48Address tofrom);
 i���
    b     :  �     �   ���������)I�� �Y.!He}���            (�/� <� �  
8 0  AdhocWifiMac (const& ctor_arg);
 o�6�    �     g  &        �����z�5�RU=ՙ���u�C�            (�/� � d  | 0  virtual void SetAckTimeout (Time a);
  � + G) constS  m     Zæ���b�+�wؘfy�         ]  �        ������6z��f����<%�ªo+            (�/� s� �  � 0  virtual void SetCtsTimeout (Time c);
  L + G) const;
 S�W�C���;lL��G    `       r        �����u�pY%�� mE�����lLg              '  6        l     `  �        ����_FB���k��7˛|����            (�/� m� $  � $  virtual void SetPifs (Time pifs);
  � %G) const  '     TÂ`*��n�jc�Q\    �     >  �   	     	�����O����6ϥ��9W4ʌ��=              
   
.      g  g   &  Mac48Address GetBssid (void) const;
    
     P  �   
     
�������-��ּ�3^xp��              �  �   D  virtual void Enqueue (Ptr<const Packet> packet, Mac48Address to);
    Z     :          ����"��~'����(@�.q�              	  	   .  virtual bool SupportsSendFrom (void) const;
    �     �  #        ������x��kq�e9�p@aئ            (�/� �� D  	B  	�   i  virtual void SetForwardUpCallback (<,Ptr<Packet>, Mac48Address> u);
  �  (   G  m_;
 Wl8�8��0������
    	     =  W     �   ������U������=L��=:.Q�            (�/� @� �  � 4  AdhocWifiMac &operator = (const);
 
�G    	S     F  ^     �   ����w�!c}$\O�*��-B��S�              
�  
�   .  virtual Mac48Address GetBssid (void) const;
  �          	�     5  �     q   ����q�P�����ϸS-���@K                   )  Ptr<DcaTxop> DoGetDcaTxop(void) const;
    	�     P  �     6   �������W�����q�lg�;�W/            (�/� ]= d    ;   Q  Ptr<DcaTxop> Get(void) const;
   S (d);
 D�VU�̰|V�    
     Y  �     l   ������Mk��P�P��~˃�ǰ              n  �   A  void ForwardUp (Ptr<Packet> packet, const WifiMacHeader *hdr);
  d  y        
w     T  �     p   ������?܍fU�DZ���i���:N              :  d   H  virtual void FinishConfigureStandard (enum WifiPhyStandard standard);
    
�     �  `     &   �����DV�g��h�Ml�&�f�!�            (�/�` E �Po�&"�!���'�/ǲ���˷�9������'M�1y����Ҡl���M�V�Z&V%���/�d���i��N��0�G�F��
�T�Cd�k��?c[��� \ms+��X��o��n�O�ť�k*��c��    ]     `  }     '      �f�|=�q&:��| ��^Dh              :  d      �  �   H  virtual void FinishConfigureStandard (enum WifiPhyStandard standard);
    �     �  }     �   �����P<J-�0> ��I�@^�3�0            (�/� �� $  :  �   T  void TxOk (const WifiMacHeader &hdr);
Failed  �  G   q  TracedCallback<> m_txOkErr \ms+�,H��m���n��)(    ?       �        �����فb�v�#�n�O(�              N  N     void DoStart ();
    ^       }        ����%]z�-��-
������D              N  a        j       �     �   �������M����2s*�fc�-�              N  N     void DoStart ();
    �    }  �        �����z?��p���|����˅�|�            (�/�`%� �r=@mC ��)���Ģ�6�RrȔ���d�L(;$�!a�KO2*�D�FQ7D�ɉ�0�-=b d d �k�7ɩ��c&l)�1�^�pG��v5��F}��)����#!��X���I.s󲑰�����؄h:.!���y���xB8Ϩhpq��ʢ\N$j��-�`����l���&�0�3[��j֛��1*��^0�GL�p��t�J!�3�e�X�$QL��ե�Z�*5IR|٤�k:l����zC5�H|0�j�mZN;�B��Onh�H4±Aـ���Vo��n��o�\��-�P��FB�Q���8`��C�ȝp��H���ՠ�7��c�n!�+ƅ��+�*�p��b�� �A�Ed*��tJ�FR��d��eto��CdJ�w�v��ö�v .!��l�SH�ؤ�k��r���Z�tZ���g˘�W<��޵��;1��p��3j�)N�M%Ob��A��$4� ��T �� �����D
�P�� ���+VnE�:��gBy����
��!��3$./�r��s��׉Jab�ӏ	^c�c�S����}�#p-"N��LM��I��K�ﺧ�S`k��y�/��������`���F��z�Qh7�vm�U�ĔMʻJv�