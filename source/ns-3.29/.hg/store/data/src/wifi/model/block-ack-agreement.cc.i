        Q  
�      �����������������G��:P|u��%            (�/�`�	=" ���(�ұ �8��K¶l�y��p�I������«� �?�?��K� � � Y��|�4o�S�}��M}�nd��w_�xރ�d��xv۫��'�u^11����.�#�z�L�s�W��B���j&��$זu~�US�5MSO�Nn�)(�\�҂�	���
����k{��'��R���^ers��;NT�J����,,b�9�\0	�����p��Ȍ��$-נ��N6V �g1(�N�[�/׭���B4�}�QXx>�(=�����>��ۇ��ɶP&�=�8�T��^�qٓ��٨~�l���7[(���c��o����+I��5�ޥS:72���d�:/7��e�,�5�T�;|:���ډo�޸v����>�)�];���{��˿-��<Sܔ���}��.�@<P�<Q3GX'f='��������$rY���=�>�؃$�W�M��NUy� �w�'��U���Gc�Ղg#�N�J�O᳋vn3�]sm��,�,~�� �`f��tI���%����]�Rћ��ޞ9������yލK����7��j)<�l�������%�lU�r�
S�i�����v��?���8���\�s���Z�����W/�;"�*>��d=�d� m����y�1&s]�p���c�O�5S��¬����!y�9�c�D.�;G�ַу�e$-Tz&a0��1���urkrZT�:�X��Rm8�șϹ������������.�ݧc�����2��L�	 �  ��� �2 � @�%J�D�(��N�K���O�jmA|[d�J��u��T�o�h-|��m�e����)D�Q�|=�?^��ߣ�U;~��̣W������`y 8��0=[�G�<3D�+��cA���|m{�w"Z�8N���a�x`��쩄s�f�'�ֶMj8A��<��L�	OtL`�N�J6"���A-�7WL�T��M/��@W��[.�&���uhT�1��y��7���Qg��.��VF��pOx�����S����C:m�I��5i/��Ϊ{�)�6e_BqI2�����q�&�AN/�`�*��S!�    Q      
2      �    ������s/�z��Qn���q            (�/�`� M �<2`A ��b?�Oğ�M7A���x�ls��7%v��p@	+`�M�5��ߑ
To, 0 . �ɨ��|j9�[�L˱*�S�*�^fQ����y��.���a�a	;�sSt��0h�X
b*��6 9�gt#�l�efdVQ���m�`7Y��/T]r�}p���KL���l_4lM�n� �- �U�O�����ĳ���
���?�3�.M�H^���l�]iv�8��p��R�#�s����je ��j�)){j����`    d     N  
/     �   ����\ߣП�8�:�K,���q˅,                   E   B/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
    �       
0     �   ������T,'��`�4�ܩ��L              
  
/   } // namespace ns3
    �    5  �     %�   �����V�u �a2,���2���.            (�/�`+]	 �  I E#include "ns3/log.h"

NS_LOG_COMPONENT_DEFINE ("BlockAckAgreement");
  �   FUNCTION (thisj A << peerstatic_cast<uint32_t> (tid)� (bufferSize� %timeout !seqt� 'supportedk� O�  �	�  	��+ `����2�-쀏�3\���Dx���j���T��]�/�0�1���
�+���6�� U���&b�;�f�ALk{lS��h����         )  �     *�   ����g.���E��Ec�/��W              _  _   namespace ns3 {

  �  �        /     �  K     +�   ������)d _z��<x�RU���            (�/�`� � Ҋ)/��	��<ό�CH�I�gJ_�-�,Q�a��"��c����O;Y��1��\g��N��h�i�S�v�9$Hz4�I�%��sW���N��x����_�m%uWAi�^E�!��e���x"���������f8��F cK�
�+�)%�:5�]�?�6  t�ق:. X� �9(�`H����K�3S����c%��	H ��l�
F1�f7�Q��{pD    +     �  W     ,�   �����|	�W'���rE�R/���            (�/�`O  4
  ( 
  ��  ��f	H�  	�
~  
~��  ��.��  5   H  NS_LOG_FUNCTION (this);
  return (m_htSupported == 1) ? true : false;
  8  K   } //namespace ns3
 @�� �a7n��v_E
n���qQ0�n`���7���ݸ�(a7�0̃#    	     �       -f   ����QG	��"����/�%L����            (�/�`
  Ҋ(+Pk ��
"�f��uIk��y���i �Y칵��>���j��j1F�����V,���z�4b-���
)Ak����D{����)���Cދ �^%D�K��Cb8���M,�����@OYa�Ъ'u�4�B�LٕC���<=��\E"�I&:)�X��
 ~�
92{Í���a�j�(���f�\    	�     ?       0�   �����˅��3�$�����ی�              �  9   3  NS_LOG_FUNCTION (this << peer << (uint16_t)tid);
    
        Y   	  3l   	�����Yy!c������J$�o�              �  L        
,     M  g   
  3�   
����n�g�#�.�:�wQ])�	G��              M  �   A  NS_LOG_FUNCTION (this << peer << static_cast<uint16_t> (tid));
    
y     6  P     4   ����(i��>ͳ�7�̿{�Yo�Y              M  �   *  NS_LOG_FUNCTION (this << peer << +tid);
    
�     -  P     4�   �����D=M��_U>���vh c              )  )   #include "ns3/log.h"
  J  _    